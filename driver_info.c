/**
 * \file            driver_info.c
 * \brief           Source file
 */

/*
 * Copyright (c) 2022
 *
 * Authors: Jason Zheng <quan3969@qq.com>
 */

#include "driver_info.h"

struct oem_driver
{
    char original_name[64];
    char version[64];
    char device_id[128];
    char status[36];
};

struct instance
{
    char id[256];
    char device_description[128];
    uint8_t match_driver[10];
};

/*
 * 用 fgets 的方法读取
 */
void
store_driver_info(void)
{

    /* 读取时触发，仅能触发一次。因此数据坐标不可用 */
    FILE *pPipe = _popen("c:\\windows\\system32\\pnputil.exe \
                         /enum-devices /drivers", "rt");
    if (pPipe == NULL) {
        exit(1);
    }

    char psBuffer[256];
    struct oem_driver found_driver[256] = {0};  /* 假设它有 256 个 oem 驱动 */
    int found_instance_count = 0;
    struct instance found_instance[128];        /* 假设它有 128 个 Instance 
                                                   需要 Oem 驱动 */

    /* 
     * 可以用 FILE 中的暂存数据做处理，前提是遍历一次便可完成。
     * 遍历找出最大的数组，以 Venus-15 TGL 为例，最大数组为 203，为 Instance ID
     */
    while (fgets(psBuffer, 256, pPipe))
    {
        if (memcmp(psBuffer, "    Driver Name:            oem", \
                   strlen("    Driver Name:            oem")) == 0)
        {
            /*
             * 找到了一个 oem dirver，大致信息如下：
             * Driver Name:            oem78.inf
             * Original Name:          tigerlakepch-lpsystem.inf
             * Provider Name:          INTEL
             * Class Name:             System
             * Class GUID:             {4d36e97d-e325-11ce-bfc1-08002be10318}
             * Driver Version:         07/18/1968 10.1.24.6
             * Signer Name:            Microsoft Windows ... Publisher
             * Matching Device ID:     PCI\VEN_8086&DEV_A0A4
             * Driver Rank:            00FF2001
             * Driver Status:          Best Ranked / Installed
             *
             * 从中存储需要的信息：
             * Oem_num, Original Name, Driver Version,  
             * Matching Device ID, Driver Status
             */

            /* 存储 Oem_num，可看作是临时变量 */
            int oem_num;
            sscanf_s(&(psBuffer[31]), "%d", &oem_num);

            /* 存储 Original Name */
            fgets(psBuffer, 256, pPipe);        /* Original Name */
            strcpy(found_driver[oem_num].original_name, &(psBuffer[28]));

            /* 存储 Driver Version */
            fgets(psBuffer, 256, pPipe);        /* Provider Name */
            fgets(psBuffer, 256, pPipe);        /* Class Name */
            fgets(psBuffer, 256, pPipe);        /* Class GUID */
            fgets(psBuffer, 256, pPipe);        /* Driver Version */
            strcpy(found_driver[oem_num].version, &( psBuffer[39]));

            /* 存储 Matching Device ID */
            fgets(psBuffer, 256, pPipe);        /* Signer Name */
            fgets(psBuffer, 256, pPipe);        /* Matching Device ID */
            strcpy(found_driver[oem_num].device_id, &(psBuffer[28]));

            /* 存储 Driver Status */
            fgets(psBuffer, 256, pPipe);        /* Driver Rank */
            fgets(psBuffer, 256, pPipe);        /* Driver Status */
            strcpy(found_driver[oem_num].status, &(psBuffer[28]));

        }

        if (memcmp(psBuffer, "Instance ID:", strlen("Instance ID:")) == 0)
        {
            /*
             * 找到了一个 Instance，大致信息如下：
             * Instance ID:                PCI\VEN_8086&DEV...1583659&0&E8
             * Device Description:         Intel(R) ... root Port #9 - A0B0
             * Class Name:                 System
             * Class GUID:                 {4d36e97d-...-08002be10318}
             * Manufacturer Name:          INTEL
             * Status:                     Started
             * Driver Name:                oem78.inf
             * Extension Driver Names:     oem102.inf
             * 
             * 首先确认它是我们要找的需要 oem_driver 的 Instance，因此要到 
             * Driver Name 里判断前面需要的信息暂存。
             *
             * 从中存储需要的信息：
             * Instance ID, Device Description, oem_driver_num
             */
            
            /* 暂存 Instance ID, Device Description 信息 */
            char temp_id[256];
            char temp_device_description[128];
            strcpy(temp_id, &(psBuffer[28]));
            fgets(psBuffer, 256, pPipe);        /* Device Description */
            strcpy(temp_device_description, &(psBuffer[28]));
            fgets(psBuffer, 256, pPipe);        /* Class Name */
            fgets(psBuffer, 256, pPipe);        /* Class GUID */
            fgets(psBuffer, 256, pPipe);        /* Manufacturer Name */
            fgets(psBuffer, 256, pPipe);        /* Status */
            fgets(psBuffer, 256, pPipe);        /* Driver Name */
            if (memcmp(psBuffer, "Driver Name:                oem", 
                       strlen( "Driver Name:                oem")) == 0)
            {
                /* 是我们需要的 instance
                   到这里说明已经至少找到一个 oem driver，因此 count 从 1 开始 */
                int found_oem_driver_count = 1;
                strcpy(found_instance[found_instance_count].id, temp_id);

                strcpy(found_instance[found_instance_count]\
                       .device_description, temp_device_description);

                sscanf_s(&(psBuffer[31]), "%d", 
                         &found_instance[found_instance_count]\
                         .match_driver[found_oem_driver_count]);

                if (memcmp(psBuffer, "Extension Driver Names:     oem", 
                           strlen( "Extension Driver Names:     oem")) == 0)
                {
                    /* 除 base driver 外还有 extension driver */
                    found_oem_driver_count ++;
                    sscanf_s(&(psBuffer[31]), "%d", 
                             &found_instance[found_instance_count]\
                             .match_driver[found_oem_driver_count]);
                    fgets(psBuffer, 256, pPipe);

                    while (memcmp(psBuffer, "                            oem",
                                  strlen("                            oem"))
                           == 0)
                    {
                        /* 有多个 extension driver */
                        found_oem_driver_count ++;
                        sscanf_s(&(psBuffer[31]), "%d", 
                                 &found_instance[found_instance_count]
                                 .match_driver[found_oem_driver_count]);
                        fgets(psBuffer, 256, pPipe);
                    }
                }
                found_instance[found_instance_count]
                    .match_driver[0] = found_oem_driver_count;
                found_instance_count ++;
            }
        }

        fputs(psBuffer, stdout);
    }

    _pclose(pPipe);
}

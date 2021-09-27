#include "test_function.h"

/*

Todo:

2021.09.23
将 pPipe 运行得到的输出存储起来。

2021.09.26: 
从暂存中读取有用数据。
    善用库：https://docs.microsoft.com/en-us/cpp/c-runtime-library/string-manipulation-crt?view=msvc-160
1. 列出所有使用中的驱动 oem_driver 。存储信息：
    1) num
    2) original_name
    3) match_device_id
    4) version
    5) status
2. 列出所有 oem 驱动和有问题（即驱动没打上）的 instance，存储信息：
    1) id
    2) description
    3) status
    4) staus oem_driver[10]
3. 根据 oem_driver 的 status 判断是否在使用，选择删除或备份。

2021.09.27:
用 strtok 让两种方法通用。

*/ 

struct oem_driver
{
    char original_name[64];
    char version[64];
    char device_id[128];
    char status[36];
};

// struct oem_driver
// {
//     char *original_name;
//     char *version;
//     char *device_id;
//     char *status;
// };

struct instance
{
    char id[256];
    char device_description[128];
    char status[13];
    unsigned char match_driver[10];
};

void tf_test( void )
{
    // tf_fread();
    // tf_fgets();
    tf_store_driver_info_fread();
}

/*

用 fread 的方法获取 driver 和 instance 数据。

*/
void tf_store_driver_info_fread( void )
{
    // 读取时触发，仅能触发一次。因此数据坐标不可用。
    FILE *pPipe = _popen( "c:\\windows\\system32\\pnputil.exe /enum-devices /drivers", "rt" );
    if( pPipe == NULL ) exit( 1 );

    // 先存到局部变量中，分多次遍历保存所需要的数据。
    int numread = 0;
    char pPipe_buffer[1048576]; // 预留 1 * 1024 * 1024 Byte = 1 MB

    // 寻找信息时用到的指针和坐标
    int pPipe_buffer_pos1;
    char *pPipe_buffer_pd1, *pPipe_buffer_pd2;

    // 假设它有 256 个 oem 驱动
    struct oem_driver found_driver[256];

    numread = fread( pPipe_buffer, sizeof( char ), 1048576, pPipe );
    
    // 找到 oemxx.inf 位置后，记录数据到数组，oem 的 num 就是数组的位数。
    int found_driver_oem_num;
    pPipe_buffer_pd1 = strstr( pPipe_buffer, "    Driver Name:            oem" );
    pPipe_buffer_pos1 = ( int )( pPipe_buffer_pd1 - pPipe_buffer + 1 );
    sscanf_s( &( pPipe_buffer[pPipe_buffer_pos1 + 30] ), "%d", &found_driver_oem_num );

    pPipe_buffer_pd1 = strstr( pPipe_buffer_pd1, "    Original Name:" );
    pPipe_buffer_pos1 = ( int )( pPipe_buffer_pd1 - pPipe_buffer + 1 );
    pPipe_buffer_pd2 = strrchr( pPipe_buffer_pd1, '\n' );
    strcpy_s( found_driver[found_driver_oem_num].original_name, ( pPipe_buffer_pd2 - pPipe_buffer_pd1 ), &( pPipe_buffer[pPipe_buffer_pos1 + 27] ) );
    ( found_driver[found_driver_oem_num].original_name )[pPipe_buffer_pd2 - pPipe_buffer_pd1] = 0;
    int temp = strlen( found_driver[found_driver_oem_num].original_name );

    pPipe_buffer_pd1 = strstr( pPipe_buffer_pd1, "    Driver Version:" );
    pPipe_buffer_pos1 = ( int )( pPipe_buffer_pd1 - pPipe_buffer + 1 );
    strcpy( found_driver[found_driver_oem_num].version, &( pPipe_buffer[pPipe_buffer_pos1 + 38] ) );

    pPipe_buffer_pd1 = strstr( pPipe_buffer_pd1, "    Matching Device ID:" );
    pPipe_buffer_pos1 = ( int )( pPipe_buffer_pd1 - pPipe_buffer + 1 );
    strcpy( found_driver[found_driver_oem_num].device_id, &( pPipe_buffer[pPipe_buffer_pos1 + 27] ) );

    pPipe_buffer_pd1 = strstr( pPipe_buffer_pd1, "    Driver Status:" );
    pPipe_buffer_pos1 = ( int )( pPipe_buffer_pd1 - pPipe_buffer + 1 );
    strcpy( found_driver[found_driver_oem_num].status, &( pPipe_buffer[pPipe_buffer_pos1 + 27] ) );

    _pclose( pPipe );

}

/*

遍历 pnputil /enum-devices /drivers 命令，获得最长字符串和大小。
    最长 Instance ID，203
    最长

*/
void tf_fread( void )
{
    // 读取时触发，仅能触发一次。因此数据坐标不可用。
    FILE *pPipe = _popen( "c:\\windows\\system32\\pnputil.exe /enum-devices /drivers", "rt" );
    if( pPipe == NULL ) exit( 1 );

    // 先存到局部变量中，分多次遍历保存所需要的数据。
    int numread = 0;
    char bbuffer[1048576]; // 预留 1 * 1024 * 1024 Byte = 1 MB
    char *pdest;
    int  result;
    char str[] = "Instance ID:";

    numread = fread( bbuffer, sizeof( char ), 1048576, pPipe );
    pdest = strstr( bbuffer, str );
    result = ( int )( pdest - bbuffer + 1 );
    _pclose( pPipe );
}

/*

遍历 pnputil /enum-devices /drivers 命令，获得最长字符串和大小。
以 Venus-15 TGL Ext 为例：
最长字符串 203.
每项前都有确定长度的名字，
    "Driver Name:                "      29
    "Instance ID"，                     175
    "Device Description"                73
    "Status"                            13
    "Driver Name"                       11
    "Extension Driver Names"            11
    "    Original Name"                 43
    "    Driver Version"                28
    "    Matching Device ID"            91
    "    Driver Status"                 36

*/
void tf_fgets( void )
{

    // 读取时触发，仅能触发一次。因此数据坐标不可用。
    FILE *pPipe = _popen( "c:\\windows\\system32\\pnputil.exe /enum-devices /drivers", "rt" );
    if( pPipe == NULL ) exit( 1 );


    char psBuffer[256];
    char temp[256];
    int bufferlen = 0;
    char str_to_compare[] = "    Driver Status";

    // 可以用 FILE 中的暂存数据做处理，前提是遍历一次便可完成。
    // 遍历找出最大的数组，以 Venus-15 TGL 为例，最大数组为 203，为 Instance ID。
    while( fgets( psBuffer, 256, pPipe ) )
    {
        if( memcmp( psBuffer, str_to_compare, strlen( str_to_compare ) ) == 0)
        {
            if( strlen( psBuffer ) > bufferlen )
            {
                bufferlen = strlen( psBuffer );
                strcpy( temp, &( psBuffer[28] ) );
            }
        }
        fputs( psBuffer, stdout );
    }

    bufferlen -= 28;

    _pclose( pPipe );

}

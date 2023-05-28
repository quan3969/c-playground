/**
 * \file            sort_token.c
 * \brief           Source file
 */

/*
 * Copyright (c) 2022
 *
 * 1. Token.h 确认需要的内存空间并分配
 * 2. 将内容存储到内存中，快速读写
 * 3. 格式化内容并存储到数组中，方便比较
 *    - 只关心宏定义名字的排序
 *    - 用 index 来进行排序
 * 4. 根据字母顺序排序
 * 5. 排序好后写入新的文件中，Token_sorted.h
 * 
 * Authors: Jason Zheng <quan3969@qq.com>
 */

#include "sort_token.h"

void
sort_token(void)
{
    char *file_cwd;

    char file_direct[256];

    file_cwd = getcwd(NULL, 0);

    sprintf(file_direct, "%s\\sort_token\\Token.h", file_cwd);

    char *file_content = read_file(file_direct);

    if (file_content == NULL)
    {
        exit(1);
    }

    printf(file_content);

    /* Free memory */
    free(file_content);
}

/*
 * 将字符串中的 token 按字母顺序排列
 * 结束后需要释放内存 free()
 * 
 * [in] 需要排序的字符串
 * [out] 排序好的字符串
 */
char
*sort_file(char *ori_content)
{

    int file_length;
    char *sort_content;

    file_length = strlen(ori_content);
    sort_content = malloc(sizeof(char) * (file_length+1));

    // get_token_num();
    // get_token_info(ori_content, 100);

    return sort_content;

}

/*
 * #define AMI_COMPATIBILITY_PKG_VERSION	0x2d
 * ^       ^                                ^
 * 1       3                                5
 * 
 * 遍历原始字符串，存储信息：
 * 1. token 开始位置
 * 2. token 长度
 * 3. name 开始位置
 * 4. name 长度
 * 5. value 开始位置
 * 6. value 长度
 * 
 * [in] 字符串
 * [in] token 结构体数组指针
 * [in] token 数量
 */
void
get_token_info(char *ori_content, int token_num)
{
    struct token {
        char *token_pd;
        char *name_pd;
        char *value_pd;
        int token_length;
        int name_length;
        int value_length;
    };

    struct token token_info[token_num];

    char *str_pd_now;

    /* 第一个 #define 是头文件声明 */
    str_pd_now = strstr(ori_content, "#define");

    for (int i = 0; i < token_num; i ++)
    {
        /* 指针位置指向下一个 token 开始的地方 */
        str_pd_now = strstr(str_pd_now, "#define");

        /* token 开始位置 */
        token_info[i].token_pd = str_pd_now;

        /* name 开始位置 */
        token_info[i].name_pd = strchr(str_pd_now, ' ') + 1;

        /* value 开始位置 */
        token_info[i].value_pd = strchr(str_pd_now, '\t') + 1;

        /* name 长度 */
        token_info[i].name_length = token_info[i].value_pd - 
                                    token_info[i].name_pd;

        /* value 长度 */
        token_info[i].value_length = strchr(str_pd_now, '\n') - 
                                     token_info[i].value_pd;
        
        /* token 长度 */
        token_info[i].token_length = strchr(str_pd_now, '\n') - str_pd_now;
    }

}

/*
 * 将文件内容读取到字符串中
 * 结束后需要释放内存 free()
 * 
 * [in] 需要读取的文件
 * [out] 读取后返回的存储位置指针
 */
char 
*read_file(char *filename)
{
    FILE *file;         /* File to read */
    int file_length;    /* File length */
    char *file_string;  /* String to store file content */

    /* Use fopen to open file, NULL means error occur */
    file = fopen(filename, "r");
    if (file == NULL) return NULL;

    /* Use fseek to move file pointer, ftell to get position */
    fseek(file, 0, SEEK_END);
    file_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory according to the file_length */
    file_string = malloc(sizeof(char) * (file_length+1));

    /* Read file content to file_string */
    for (int i = 0; ; i++)
    {
        char c = fgetc(file);

        /* Reach end, put \0 as final char, stop read */
        if (c == EOF)
        {
            file_string[i] = '\0';
            break;
        }

        file_string[i] = c;
    }

    /* Close the file */
    fclose(file);

    return file_string;

}
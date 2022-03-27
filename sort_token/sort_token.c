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

    get_info();

    return sort_content;

}

/*
 * 遍历原始字符串，存储信息：
 * 1. token 开始位置
 * 2. token 长度
 * 3. token name 开始位置
 * 4. token name 长度
 * 5. token value 开始位置，
 * 6. token value 长度
 * token 数量 num
 * 
 * [in] 字符串
 * [out] info[num][6]
 */
void
get_info(void)
{

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
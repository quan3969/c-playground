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

    char *file_contents = read_file(file_direct);

    if (file_contents == NULL)
    {
        exit(1);
    }

    printf(file_contents);

    /* Free memory */
    free(file_contents);
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
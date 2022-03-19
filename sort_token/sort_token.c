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
 * 4. 根据字母顺序排序
 * 5. 排序好后写入新的文件中，Token_sorted.h
 * 
 * Authors: Jason Zheng <quan3969@qq.com>
 */

#include "sort_token.h"

void
sort_token(void)
{
    FILE *ori_file, *mod_file;

    char read_line[256][256];

    ori_file = fopen("C:\\Users\\Q3aN.AMD\\repo\\c-playground\\sort_token\\Token.h", "r");
    if (ori_file == NULL) printf("Fail open file.");

    for (int i = 0; i < 256; i ++)
    {
        for (int j = 0; ; j ++)
        {
            read_line[i][j] = fgetc(ori_file);
            if (read_line[i][j] == '\n') break;
        }
    }

    fclose(ori_file);
}
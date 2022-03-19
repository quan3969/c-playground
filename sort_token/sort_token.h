/**
 * \file            driver_info.h
 * \brief           Include file
 */

/*
 * Copyright (c) 2022
 *
 * Token.h 由 AMI 编译器生成，当编译进行到第二次清空 Build 时，生成的 Token.h 
 * 便是最终的 Token.h 
 * 
 * 宏定义顺序由代码中定义的顺序决定，会受到 overwrite 影响
 * 
 * 为方便比较差异，需要将它们按一定规则排序，此程序会将同目录下的 Token.h
 * 宏定义按字母大小写进行排序，生成 Token_sorted.h
 * 
 * Authors: Jason Zheng <quan3969@qq.com>
 */
                                                                              
#ifndef SORT_TOKEN_H
#define SORT_TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <process.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void sort_token(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SORT_TOKEN_H */

/**
 * \file            mian.c
 * \brief           Source file
 */

/*
 * Copyright (c) 2022
 *
 * Authors: Jason Zheng <quan3969@qq.com>
 */

#include "my_function.h"  
#include "driver_info/driver_info.h"
#include "sort_token/sort_token.h"

int
main(int argc, char *argv[], char **envp)
{
    sort_token();
    
    system("pause");

    return 0;
}

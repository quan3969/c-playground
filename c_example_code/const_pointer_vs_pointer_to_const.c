/*******************************************************************************
*
* Program: Constant Pointer VS. Pointer To A Const
*
* Description: The difference between a constant pointer and a pointer to a
* constant in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=egvGq3WSF9Y
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* char *const constant_pointer = &a;
* const char *pointer_to_const = &a;
* const char *const constant_pointer_to_constant = &a;
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = 'a';
    char b = 'b';

    char *const constant_pointer = &a;

    *constant_pointer = 'x';
    // constant_pointer = &b; // not allow

    printf("a: %c\n", a);

    const char *pointer_to_const = &a;

    pointer_to_const = &b;
    // *pointer_to_const = 'y'; // not allow

    printf("*pointer_to_const: %c\n", *pointer_to_const);

    const char *const constant_pointer_to_constant = &a;

    // *constant_pointer_to_constant = 'x'; // not allow
    // constant_pointer_to_constant = &b; // not allow

    system("pause");

    return 0;
}
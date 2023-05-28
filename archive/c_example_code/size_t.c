/*******************************************************************************
*
* Program: size_t Type Example
* 
* Description: Example of using the size_t type in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nBJuP_un20M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* strlen sotre result into int
* int: -2,147,483,648 to 2,147,483,647
* size_t: 0 to 18446744073709551615
*
* printf %zu 
*    u: unsigned integer
*    z: length modifier
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    char *string = "abcdef";

    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        printf("string[%d] = %c\n", i, string[i]);
    }

    int _int = 2147483648;

    printf("_int: %d\n",  _int);

    size_t _size_t = 2147483648;

    printf("_size_t: %zu\n", _size_t);

    printf("SIZE_MAX: %zu\n", SIZE_MAX);

    system("pause");
}
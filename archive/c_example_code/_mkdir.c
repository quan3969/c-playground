/*******************************************************************************
*
* Program: _mkdir() Demonstration
*
* Description: Example of using the _mkdir() function in C to create a file 
* system directory. The function is available on Windows machines/compilers 
* using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VHsWVQXoTMI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* 
*
*******************************************************************************/

#include <stdio.h>
#include <direct.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int retval = _mkdir("test");

    if (retval == -1)
    {
        printf("Make diretory failed.\n");

        if (errno == EEXIST) printf("Directory already exist.\n");
        if (errno == ENOENT) printf("Path not found.\n");

        system("pause");
        return 1;
    }
    printf("Make directory succeeded.\n");

    system("pause");
    return 0;
}
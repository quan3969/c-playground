/*******************************************************************************
*
* Program: _chdir() Demonstration
*
* Description: Example of using the _chdir() function in C to change the current
* working directory of the executing program.  The function is available on 
* Windows machines/compilers using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=g7tqnYfmJ2s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* _chdir _getcwd
* errno to a specific error code
*
*******************************************************************************/

#include <stdio.h>
#include <direct.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    char buffer[1024];

    if (_getcwd(buffer, 1024) == NULL)
    {
        printf("Get current working directory fail.\n");
    }

    printf("Current working directory: \n%s\n\n", buffer);

    char *newdir = "C:\\badpath";
    printf("Try to change to a path that not exist: C:\\badpath\n");

    if (_chdir(newdir) == -1)
    {
        printf("Change current working directory fail.\n");

        if (errno == ENOENT)
            printf("Path not found.\n\n");
    }

    if (_getcwd(buffer, 1024) == NULL)
    {
        printf("Get current working directory fail");
    }

    char *newdir2 = "C:\\Users\\Public";
    printf("Try to change to a vaild path: C:\\Users\\Public\n");

    if (_chdir(newdir2) == -1)
    {
        printf("Change current working directory fail.\n\n");

        if (errno == ENOENT)
            printf("Path not found.\n\n");
    }

    if (_getcwd(buffer, 1024) == NULL)
    {
        printf("Get current working directory fail");
    }

    printf("Current working directory: \n%s\n\n", buffer);

    system("pause");
    return 0;
}
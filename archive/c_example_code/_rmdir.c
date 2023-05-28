/*******************************************************************************
*
* Program: _rmdir() Demonstration
*
* Description: Example of using the _rmdir() function in C to remove a file 
* system directory.  The function is available on Windows machines/compilers 
* using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7g_w-cxgZB4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
*
*******************************************************************************/

#include <stdio.h>
#include <direct.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int retval;

    retval = _rmdir("test");

    if (retval == -1)
    {
        printf("Remove directory failed.\n");

        if (errno == ENOENT) printf("Path not found.\n");
        if (errno == ENOTEMPTY) printf("Directory not empty.\n");
        if (errno == EACCES) printf ("An open handle to the direcotry exists.\n");

        system("pause");
        return 1;
    }

    printf("Remove directory succeeded.\n");
    
    system("pause");
    return 0;
}
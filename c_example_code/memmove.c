/*******************************************************************************
*
* Program: memmove() Function
* 
* Description: Example of using the memmove() function in C.  The memmove() 
* function allows us to copy a block of data from one location in memory to 
* another. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=DGwdAQauEV4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* memmove: will not overlap
* memcpy: performance
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    int source[10] = {1,2,3,4,5,6,7,8,9,10};
    int destination1[10];
    int destination2[10];

    memmove(destination1, source, sizeof(int) * 10);
    memcpy(destination2, source, sizeof(int) * 10);

    return 0;


}
/*******************************************************************************
*
* Program: Find Middle Index Without Integer Overflow
* 
* Description: In the below C program we demonstrate why l + (r - l) / 2 
* [or start + (end - start) / 2] is a better way to calculate the middle of two 
* indexes of an array, compared to using (l + r) / 2 [or (start + end) / 2], 
* because the first approach is less prone to integer overflow errors than the 
* second the approach.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=JNFGvjATOUA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* To prevent integer overflow.
*
*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};

    int l = 1500000000;
    int r = 1900000000;

    char *massive = malloc(2000000000);
    massive[1700000000] = 'Y';

    int middle1 = (l + r) / 2;
    int middle2 = l + (r - l) / 2;

    printf("middle1: %d\n", middle1);
    printf("middle2: %d\n", middle2);

    printf("massive[%d] = %c\n", middle2, massive[middle2]);

    printf("INT_MAX: %d\n", INT_MAX);

    free(massive);
    
    system("pause");

}
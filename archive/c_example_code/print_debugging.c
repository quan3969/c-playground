/*******************************************************************************
*
* Program: Print Debugging Example
*
* Description: One debugging technique is to insert print statements into our
* code in order to trace its execution, both the control-flow and the state
* of variables throughout the execution of the program.  This technique is
* generally called "print debugging" or sometimes "printf debugging".  The below
* program is a demonstration of the concept.
*
* YouTube Lesson: https://www.youtube.com/watch?v=H-H3fX72pd0
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
#include <stdlib.h>

int main()
{
    int array[] = {4,3,6,5,7,0,9,8,1,2};
    int length = 10;

    int max = array[0];

    printf("initial max: %d\n", max);

    for (int i = 1; i < length; i++)
    {
        printf("loop - i: %d, array[%d]: %d, max: %d\n", i, i, array[i], max);

        if (array[i] > max)
        {
            max = array[i];

            printf("  IF - max: %d\n", max);
        }
    }

    printf("max: %d\n", max);

    system("pause");
    return 0;
}

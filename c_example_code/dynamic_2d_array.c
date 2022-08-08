/*******************************************************************************
*
* Program: Dynamically Allocating A 2D Array
* 
* Description: Dynamically allocating a 2D array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZLc_OpzND2c 
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
    int rows = 3;
    int cols = 3;

    int **array = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
        array[i] = malloc(sizeof(int) * cols);

    for (int i = 0; i < rows; i++)
        free(array[i]);
    
    free(array);
    
    system("pause");
    return 0;
}

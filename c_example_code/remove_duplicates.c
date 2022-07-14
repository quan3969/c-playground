/*******************************************************************************
*
* Program: Remove Duplicate Array Elements
*
* Description: Program to remove the duplicate elements from an array in C.  
* This solution involves creating another dynamically allocated array on the 
* heap that contains the same elements as the original array with the duplicates
* removed.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vJLt_VG8bqA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* malloc realloc 
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *remove_duplicates(int array[], int length, int *new_length);

int main()
{
    int test[] = {1,2,3,4,1,2,5,6,7,8};
    int after_length = 0;

    int *after = remove_duplicates(test, 10, &after_length);

    for (int i = 0; i < after_length; i++)
    {
        printf("after[%d] = %d\n", i, after[i]);
    }

    free(after);

    system("pause");
    return 0;
}

int *remove_duplicates(int array[], int length, int *new_length)
{
    int *new_array = malloc(length * sizeof(int));

    int unique_count = 0;

    for (int i = 0; i < length; i++)
    {
        bool is_unique = true;
        for (int j= 0; j < unique_count; j++)
        {
            if (new_array[j] == array[i])
            {
                is_unique = false;
                break;
            }
        }

        if (is_unique)
        {
            new_array[unique_count] = array[i];
            unique_count++;
        }
    }

    if (unique_count != length)
        new_array = realloc(new_array, unique_count * sizeof(int));

    *new_length = unique_count;

    return new_array;

}

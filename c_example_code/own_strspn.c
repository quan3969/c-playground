/*******************************************************************************
*
* Program: Create Your Own strspn() Function
* 
* Description: Example of how to create your own strspn() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=oMXhxEpznoc 
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
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

size_t _strspn(const char *str1, const char *str2);

int main()
{
    char *string = "12334abcdef";
    char *digits = "1234567890";

    size_t length = strspn(string, digits);

    printf("Initial Substing Length: %zu\n", length);

    length = _strspn(string, digits);
    printf("Initial Substing Length: %zu\n", length);

    system("pause");
    return 0;
}

size_t _strspn(const char *str1, const char *str2)
{
    size_t initial_length = 0;

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    for (size_t i = 0; i < len1; i++)
    {
        bool found_match = false;
        for (size_t j = 0; j < len2; j++)
        {
            if (str2[j] == str1[i])
            {
                found_match = true;
                break;
            }
        }

        if (!found_match) break;
        else initial_length++;
    }

    return initial_length;
}

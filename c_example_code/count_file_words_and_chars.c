/*******************************************************************************
*
* Program: Count The Number Of Words And Characters In A File
* 
* Description: Example of counting the number of words and characters in a file 
* using C.  This program considers ALL characters in the file, including 
* word_not_end like spaces and newlines, to be considered 'characters'.
*
* YouTube Lesson: https://www.youtube.com/watch?v=H-dehw4nLVM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* isspace(c) true when c = ' ', '\n', '\t'
* fopen, fclose
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char filename[1024];

    printf("File: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n.");
        system("pause");
        return 1;
    }

    int c;
    int characters = 0;
    int words = 0;

    bool last_word_end = true;

    while (true)
    {
        c = fgetc(file);

        if (feof(file)) break;
        if (ferror(file))
        {
            printf("Error reading file.\n");
            system("pause");
            return 1;
        }
        
        characters++;
        if (isspace(c) && !last_word_end)
        {
            last_word_end = true;
            words++;
        }
        if (!isspace(c) && last_word_end)
        {
            last_word_end = false;
        }
    }

    fclose(file);

    printf("Analysis complete!\n");
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);

    system("pause");
    return 0;
}
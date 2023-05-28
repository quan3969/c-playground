/*******************************************************************************
*
* Program: function pointer vs. &function pointer
* 
* Description: In C there is no difference between function and &function in 
* that both will give us a pointer to the function, we demonstrate this in the
* code below.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-41q4ugE8hE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* void (*fnc_prt1)() = function;  (*fnc_prt1)();
* void (*fnc_prt2)() = &function; fnc_prt1();
* No diff
* 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void function()
{
    printf("Function!\n");
}

int main()
{
    void (*fnc_prt1)() = function;

    (*fnc_prt1)();
    fnc_prt1();

    void (*fnc_prt2)() = &function;

    (*fnc_prt2)();
    fnc_prt2();

    printf("%p\n", fnc_prt1);
    printf("%p\n", fnc_prt2);

    system("pause");

    return 0;
}
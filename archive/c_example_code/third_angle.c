/*******************************************************************************
*
* Program: Find The Third Angle Of A Triangle
* 
* Description: Program to find the third angle of a triangle when the first two 
* angles have been provided from user input with C.  The program utilizes the 
* property that the sum of the angles of a triangle must equal 180 degrees.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wZ0BxDNQTCw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*******************************************************************************
*
* printf and scanf
* %lf: double
*
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    double angle1, angle2, angle3;

    printf("angle1: ");
    // %lf: double
    scanf("%lf", &angle1);

    printf("angle2: ");
    scanf("%lf", &angle2);

    // if ((angle1 > 0 && angle1 < 180) &&
    //     (angle1 > 0 && angle2 < 180) &&
    //     ((angle1 + angle2) < 180))
    // {
    //     angle3 = 180 - angle1 - angle2;

    //     printf("angle3: %f\n", angle3);

    // } else {
    //     printf("angle1 or angle2 is invalid!\n");
    // }

    if (!(angle1 > 0 && angle1 < 180)) 
    {
        printf("angle1 is invalid!\n");
        system("pause");
        return 0;
    }
    if (!(angle2 > 0 && angle2 < 180)) 
    {
        printf("angle2 is invalid!\n");
        system("pause");
        return 0;
    }
    if (!((angle1 + angle2) < 180))
    {
        printf("angle1 + angle2 is invalid!\n");
        system("pause");
        return 0;
    }
    angle3 = 180 - angle1 - angle2;
    printf("angle3: %f\n", angle3);

    system("pause");
    return 0;
}
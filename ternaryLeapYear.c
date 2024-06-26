/**
 * C program to check leap year using ternary conditional operator
 */

#include <stdio.h>

int main()
{
    int year;
 
    /*
     * Input year from user
     */
    printf("Enter any year: ");
    scanf("%d", &year);

    /*
    if (year % 4 == 0 && year %100 != 0)
        printf("LEAP YEAR.");
    else if (year %400 == 0)
        printf("LEAP YEAR.");
    else
        printf("COMMON YEAR.");
    */

   (year % 4 == 0 && year %100 != 0) ? printf("LEAP YEAR.") : 
        (year %400 == 0) ? printf("LEAP YEAR.") : 
            printf("COMMON YEAR.");
    
    return 0;
}
/* Write a program that acquire users enter date information that format lise mm/dd/yy
 * and then display them by yyymmdd.
 *
 * Wirte a program that accepts the date information entered by the user
 * in year/month/day (i.e. mm/dd/yy) format and displays it in year/month/day
 *  (i.e. yyyymmdd) format.
 */
#include <stdio.h>

int main(void)
{
    int yyyy, mm, dd;
    printf("Enter a date (mm/dd/yyyy):");
    scanf("%d / %d / %d", &mm, &dd, &yyyy);

    printf("You entered the date %d%.2d%.2d\n", yyyy, mm, dd);

    return 0;
}
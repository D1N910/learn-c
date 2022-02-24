#include <stdio.h>

int main(void)
{
    int time_of_24_hour_h, time_of_24_m, time_of_12_hour_h;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &time_of_24_hour_h, &time_of_24_m);

    if (time_of_24_hour_h <= 12) {
        time_of_12_hour_h = time_of_24_hour_h;
    } else if (time_of_24_hour_h < 24){
        time_of_12_hour_h = time_of_24_hour_h % 12;
    } else {
        time_of_12_hour_h = 24;
    }


    printf("Equivalent 12-hour time: %d:%.2d ", time_of_12_hour_h, time_of_24_m);
    
    if (time_of_24_hour_h > 12) {
        printf("PM");
    } else {
        printf("AM");
    }

    printf("\n");

    return 0;
}
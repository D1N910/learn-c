/* Computes the dimensional weight of a 12'' x 10'' x 8'' box */

#include <stdio.h>
#define INCHES_PER_POUND 166

int main(void)
{
    int height, length, width, volume, weight;
    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);
    volume = height * length * width;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume: %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}
/* P24 PROGRAMMING PROBLEM 3 */

/* Write a program that can compute ball volumn.The ball'r is 10m.
 * 参考公式 v = (4/3)pair^3. Attetion: divide number 4/3 ought to wire
 * like 4.0f/3.0f
 * Write a program to calculate the volumn of sphere, where the radio of sphere
 * is 10 m, referring to the formula v = 4/3πr^3.Note that fraction 4/3 should be
 * written as 4.0/3.0f.
 */

#include <stdio.h>
#define PI 3.141592f
#define SPHERE_VOLUMN_FORMULA 4.0f / 3.0f

int main(void)
{
    float sphere_radius;
    printf("Sphere radius :");
    scanf("%f", &sphere_radius);
    printf("The volumn of sphere is: %f\n", SPHERE_VOLUMN_FORMULA * PI * sphere_radius * sphere_radius * sphere_radius);
    return 0;
}
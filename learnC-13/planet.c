#include <stdio.h>
#include <string.h>

#define NUM_PLANENTS 9

/**
 * @brief 对比planet 是否相等
 * 
 */
void check_planet(char *check_string, char *planet[]);

int main(int argc, char *argv[])
{
    int argv_index = 1;
    char *planet[] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Neptune",
        "Pluto"
    };
    while (argv_index <= argc)
    {
        check_planet(argv[argv_index++], planet);
    }
    
    return 0;
}

void check_planet(char *check_string, char *planet[]) {
    int planet_index = 0;
    while (planet_index < NUM_PLANENTS)
    {
        if (strcmp(check_string, planet[planet_index]) == 0) {
            printf("%s is planet %d \n", check_string, planet_index + 1);
            return;
        }
        
        planet_index++;
    }
    printf("%s is not a planet \n", check_string);
    return;
}
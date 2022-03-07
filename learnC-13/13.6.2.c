#include <stdio.h>
#include <string.h>

char *my_strcat(char *s1, const char *s2);

int main(void)
{
    char my_test[1000] = "hey12345";
    char *p = my_test;
    p += 9;
    *p = '?';
    p++;
    *p = '!';
    printf("%c \n", *p);
    printf("%s \n", my_test);
    char my_tt[100] = "poqwe";
    char my_tt2[101] = "ui";
    my_strcat(my_tt, my_tt2);
    printf("%s \n", my_tt);
    return 0;
}

char *my_strcat(char *s1, const char *s2)
{
    char *p = s1;

    while (*p != '\0')
        p++;
    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}
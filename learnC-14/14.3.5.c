#include <stdio.h>

#define ECHO(s) (gets(s), puts(s))

int main(void) {
    char my_str[100];
    ECHO(my_str);
    return 0;
}
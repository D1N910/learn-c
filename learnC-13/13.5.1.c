#include <stdio.h>
#include <string.h>

int main(void)
{
    char my_test[1000];
    strcpy(my_test, "sdkfk111fj");
    printf("%s\n", my_test);
    puts(my_test);
    printf("%ld\n", strlen(my_test));
    return 0;
}
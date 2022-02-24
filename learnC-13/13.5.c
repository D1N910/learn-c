#include <stdio.h>
#include <string.h>

int main(void)
{
    char my_string[30] = "To C or not to C.";
    printf("%s \n", strcat(my_string, "LLL"));
    printf("%d \n", sizeof(my_string));
    strcpy(my_string, "lkjflkdjf");
    printf("%d \n", strlen(my_string));
    printf("%s \n", my_string);
    puts(my_string);
    return 0;
}
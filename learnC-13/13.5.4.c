#include <stdio.h>
#include <string.h>

int main(void)
{
    char my_test[1000] = "hey12345";
    char my_test2[1000] = "hey1";
    char my_test1[1000] = "hey1";
    printf("%s \n", strcpy(my_test, my_test1));
    return 0;
}
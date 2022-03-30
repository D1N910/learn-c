#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
    
} NODE, * PNODE;

struct  Stack
{
    PNODE pTop; // 指向栈的顶部
    PNODE pBottom; // 指向栈的底部
};


int main(void)
{
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node // 箱子里的书
{
    int data;
    struct Node * pNext;
    
} NODE, * PNODE;

typedef struct Stack // 栈  - 箱子
{
    PNODE pTop; // 指向栈的顶部
    PNODE pBottom; // 指向栈的底部
} STACK, * PSTACK;


int main(void)
{
    return 0;
}


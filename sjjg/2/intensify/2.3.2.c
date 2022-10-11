#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct LNode
{
    /* data */
    ElemType data;
    LNode * next;
} LNode, *LinkLisk;

LinkLisk List_HeadInter(LinkLisk L) {
    LNode *s; int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    while (/* condition */)
    {
        /* code */
    }
    
}

int main() {
    return 0;
}
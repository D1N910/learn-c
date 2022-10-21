// 不带头结点的链栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next; // 顶部指针
}LinkNode, *LiStack;

// 入栈
void Push(LiStack * L, ElemType x) {
    LiStack S;
    S = (LiStack)malloc(sizeof(LiStack));
    S->data = x;
    S->next = *L;
    *L = S;
}


// 出栈
_Bool Pop(LiStack * L, ElemType *x) {
    if (L == NULL)
        return false;
    *x = (*L)->data;
    LiStack S = *L;
    *L = (*L)->next;
    free(S);
    return true;
}

// 获得栈顶数据
_Bool GetTop(LiStack L, ElemType *x) {
    if (L == NULL)
        return false;
    *x = L->data;
    return true;
}

// 判断栈是否为空
_Bool EmptyStack(LiStack L) {
    if (L == NULL)
        return true;
    return false;
}



int main() {
    LiStack L;
    L = NULL;
    int x;
    Push(&L, 1);
    Push(&L, 2);
    if (L != NULL) {
        printf("1-1 %d 1-1 \n", L->data);
    }
    if (L->next != NULL) {
        printf("1-1 %d 1-1 \n", L->next->data);
    }
    if (Pop(&L, &x))
        printf("!! %d !!\n", x);
    if (Pop(&L, &x))
        printf("!! %d !!\n", x);
    return 0;
}
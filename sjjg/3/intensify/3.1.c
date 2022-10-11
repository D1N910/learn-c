#include <stdio.h>
#include <stdbool.h>

#define Maxsize 10
#define ElemType int

typedef struct  {
    ElemType data[Maxsize]; // 栈元素
    int top; // 栈顶指针
} SqStack;

// 进栈
_Bool InitStack(SqStack *S, ElemType x) {
    if (S->top == Maxsize -1)
        return false;
    S->data[++S->top] = x;
    return true;
}

// 出栈
_Bool Pop(SqStack *S, ElemType *x) {
    if (S->top == -1) // 栈为空
        return false;
    *x = S->data[S->top--];
    return true;
}

// 获得栈顶元素
_Bool GetTop(SqStack S, ElemType *x) {
    if (S.top == -1) // 栈为空
        return false;
    *x = S.data[S.top];
    return true;
}

// 判空，false 为非空，true 为空
_Bool StackEmpty(SqStack S) {
    return S.top == -1;
}

int main() {
    SqStack S;
    S.top = -1; // 初始化栈顶指针
    int x; // 存储数据元素
    InitStack(&S, 1);
    if (Pop(&S, &x))
        printf("%d Success \n", x);
    if (StackEmpty(S))
        printf("Stack is NULL\n");
    InitStack(&S, 2);
    if (GetTop(S, &x))
        printf("%d get top Element Success\n", x);
    if (!StackEmpty(S))
        printf("Stack not NULL\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50
#define Elemtype int
typedef struct Strack
{
    Elemtype data[MaxSize];
    int top;
    /* data */
} STRACK, *SqSTRACK;

void InitStack(SqSTRACK); // 初始化一个空栈 S

_Bool StackEmpty(STRACK); // 判断一个栈是否为空，若栈 S 为空则返回 true，否则返回 false

_Bool Push(SqSTRACK, Elemtype); // 进栈，若栈 S 未满，则将 x 加入使之成为新栈顶。

_Bool Pop(SqSTRACK, Elemtype*); // 出栈，若栈 S 非空，则弹出栈顶元素，并用 x 返回栈顶元素。

_Bool GetTop(STRACK, Elemtype*); // 读取栈顶元素，若栈 S 非空，则用 x 返回栈顶元素。

void DestoryStack(SqSTRACK); // 销毁栈，并释放栈 S 占用的存储空间("&"表示引用)

int main(void)
{
    STRACK S;
    Elemtype x;

    InitStack(&S);

    Push(&S, 2);
    GetTop(S, &x);
    printf("Get Top: %d\n", x);

    Push(&S, 4);
    GetTop(S, &x);
    printf("Get Top: %d\n", x);
    printf("isNull: %d\n", StackEmpty(S));

    Pop(&S, &x);
    GetTop(S, &x);
    printf("Get Top: %d\n", x);

    DestoryStack(&S);
    printf("isNull: %d\n", StackEmpty(S));

    return 0;
}

void InitStack(SqSTRACK S) {
    S->top = -1;
}

_Bool StackEmpty(STRACK S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

_Bool Push(SqSTRACK S, Elemtype x)
{
    if (S->top == MaxSize - 1) {
        return false;
    } else {
        S->data[++S->top] = x;
        return true;
    }
}

_Bool Pop(SqSTRACK S, Elemtype* x)
{
    if (StackEmpty(*S)) {
        return false;
    } else {
        *x = S->data[S->top--];
        return true;
    }
}

_Bool GetTop(STRACK S, Elemtype* x)
{
    if (StackEmpty(S)) {
        return false;
    } else {
        *x = S.data[S.top];
        return true;
    }
}


void DestoryStack(SqSTRACK S) {
    S->top = -1;
}
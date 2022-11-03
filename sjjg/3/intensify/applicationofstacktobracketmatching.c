// 栈在括号匹配中的应用 2022.10.21
#include <stdio.h>
#include <stdbool.h>

#define Maxsize 10

typedef struct 
{
    char data[Maxsize]; // 静态数组
    int top; // 栈顶指针
} SqStack;

// 初始化一个栈
void initStack(SqStack * S) {
    S->top = -1; // 初始为置为-1
}

_Bool Push(SqStack * S, char x) {
    if (S->top == Maxsize - 1)
        return false; // 判满
    S->data[++S->top] = x;
    return true;
}

_Bool StackEmpty(SqStack S) {
    return S.top == -1;
}

_Bool Pop(SqStack * S, char * x) {
    if (StackEmpty(*S))
        return false; // 判空
    *x = S->data[S->top--];
    return true;
}


/// @brief 括号匹配
/// @param str 输入的括号序列
/// @param length 输入的长度
/// @return 
_Bool bracketcheck(char str[], int length) {
    SqStack S;
    initStack(&S); // 初始化一个栈
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '['|| str[i] == '{') {
            Push(&S, str[i]); // 扫描到左括号，入栈
        } else { // 是右括号
            // 扫描到右括号，且栈空，匹配失败
            if (StackEmpty(S))
                return false;

            char topElem;
            Pop(&S, &topElem); // 栈顶元素出栈
           if (topElem == '(' && str[i] != ')') {
                return false; // 匹配不上，失败
            }
            if (topElem == '[' && str[i] != ']') {
                return false; // 匹配不上，失败
            }
            if (topElem == '{' && str[i] != '}') {
                return false; // 匹配不上，失败
            }
        }
    }

    return StackEmpty(S); // 检查所有元素后，栈空说明匹配成功
}

int main() {
    FILE *fp = fopen("text.txt", "w");
    if (fp == NULL) {
        printf("哈哈!");
    }

    for (int i = 0;i<1000;i++)
        fputs("我爱你 world!", fp);
    fclose(fp);
    // short b = -1;
    // int c = b;
    // printf("%d", c);
    // char s[10] = "1+1+2+3";
    // printf("%s", s);
    // char str[6] = { '(', '(', '{', '}', ')', ')' };
    // char str1[6] = { '(', '(', '{', '}', ')', ')' };
    // if (bracketcheck(str, 6))
    //     printf("str - Success! \n");
    // else
    //     printf("str - Fail! \n");
    // if (bracketcheck(str1, 6))
    //     printf("str1 %s - Success! \n", str1);
    // else
    //     printf("str1 - Fail! \n");
}
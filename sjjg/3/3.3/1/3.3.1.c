// 括号匹配
#include <stdio.h>
#include <stdbool.h>
#include "strack.c"

_Bool CheckIfLeft(char c);

int LeftRightIsSameType(char l, char r);

int GetIndex(char c);

int main(void)
{
    Strack S;
    InitStrack(&S);

    _Bool successMatch = true;

    char c[] = "()()()()(()";
    for (int i = 0; i <= sizeof(c) - 2; i++) {
        if (CheckIfLeft(c[i])) { // 如果是左括号，那么入栈
            EnStrack(&S, c[i]);
        } else { // 如果不是左括号，那么出栈并进行比对
            char x;
            if (OutStrack(&S, &x)) { // 如果出栈成功
                if (LeftRightIsSameType(x, c[i]) == 0) {
                    successMatch = false;
                    printf("左右括号类型不一致");
                    break;
                }
            } else { // 如果出栈失败，说明没有左括号了
                successMatch = false;
                printf("栈里没有可以用来匹配的左括号了！");
                break;
            }
        }
    }
    if (!ifStrackEmpty(S)) {
        successMatch = false;
        printf("还有剩余的左括号！");
    }
    if (successMatch) {
        printf("成功匹配！");
    }
    return 0;
}

// 检查是不是左括号
_Bool CheckIfLeft(char c) {
    switch (c)
    {
    case '(':case '[':case '{':
        return true;
    break;
    
    default:
        return false;
        break;
    }
}

// 检查是否同一类型
int LeftRightIsSameType(char l, char r) {
    //   ( { [
    // ) 1 0 0
    // } 0 1 0
    // ] 0 0 1
    int config[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    return config[GetIndex(l)][GetIndex(r)];
}

// 获得符号的index
int GetIndex(char c) {
    switch (c)
    {
    case '(':case ')':
        return 0;
        break;
    case '{':case '}':
        return 1;
        break;
    case '[':case ']':
        return 2;
        break;
    default:
        break;
    }
    return 0;
}

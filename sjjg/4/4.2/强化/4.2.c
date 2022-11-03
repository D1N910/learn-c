// 22:12
#include <stdio.h>
#define MaxLength 50
typedef struct 
{
    char ch[MaxLength];
    int length;
} SString;

// 朴素模式匹配算法
int Index(SString, SString);

// 赋值操作
void StrAssign(SString *, char *);

int main() {
    SString S;
    SString T;
    char chars2[3] = "abaabc\0";
    char chars[7] = "abaabcdabcd\0";
    StrAssign(&T, chars2);
    StrAssign(&S, chars);
    printf("S is %s \n", S.ch);
    printf("T is %s \n", T.ch);
    printf("Index is %d \n", Index(S, T));
    return 0;
}

void StrAssign(SString * S, char * chars) {
    // C语言字符串的最后一位是‘\0’
    int i = 0;
    S->ch[0] = ' ';
    while (chars[i] != '\0')
    {
        S->ch[i + 1] = chars[i];
        i++;
    }
    S->length = i;
}
int Index(SString S, SString T) {
    int i = 1, j = 1; // 定义两个工具指针
    while (i<=S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
        /* code */
    }
    if (j > T.length) return i - T.length; // 因为最后还i++
    return 0; // 匹配失败返回0
}
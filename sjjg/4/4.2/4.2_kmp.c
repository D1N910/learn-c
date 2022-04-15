/**
 * @file 4.1_2.c 基本操作实现，用方案4
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 255 // 预定串的长度是 255

// 静态数组实现（定长顺序存储）
typedef struct {
    char ch[MAXSIZE]; // 每个分量存储一个字符，系统会自动回收空间
    int length; // 串的实际长度
}SString;

/**
 * @brief 求串长。返回串S的元素个数。
 * 
 * @return int 
 */
int StrLength(SString);

/**
 * @brief 清空操作。将S清空为空串。—— 空间还能用
 * 
 */
void ClearString(SString *);

/**
 * @brief Construct a new Sub String object
 * 求子串。用Sub返回串S的第pos个字符起长度为len的子串
 * 
 */
_Bool SubString(SString *, SString, int, int);

/**
 * @brief 清空操作。将S清空为空串。—— 空间还能用
 * 
 * @return _Bool 
 */
_Bool StrEmpty(SString);

/**
 * @brief 比较操作。若 S>T，则返回值 > 0；若S=T，则返回值=0；如果S < T , 则返回值 < 0。
 * 
 */
int StrCompare(SString, SString);

/**
 * @brief 定位操作。若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数为0.
 * 
 * @return int 
 */
int Index1(SString, SString);

int Index2(SString, SString);

/**
 * @brief 定位操作。若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数为0.
 * 
 * @return int 
 */
int Index_KMP(SString, SString, int next[]);


/**
 * @brief 赋值操作。把串T赋值为chars
 * 
 */
_Bool StrAssign(SString *, char[]);

/**
 * @brief next算法实现
 * 
 */
void GetNext(SString, int[]);

int main() {
    SString S;
    SString Sub;
    S.length = 5;
    S.ch[1] = 'c';
    S.ch[2] = 'b';
    S.ch[3] = 'd';
    S.ch[4] = 'f';

    if (SubString(&Sub, S, 3, 1)) {
        printf("成功地成功了 %c \n", S.ch[2]);
        printf("成功地成功了 %c \n", Sub.ch[1]);
    }
    printf("比较是否相等 %d \n", StrCompare(S, Sub));
    printf("获取对应下标 %d \n", Index1(S, Sub));
    printf("获取对应下标 %d \n", Index2(S, Sub));
}

int StrLength(SString S)
{
    return S.length;
}

void ClearString(SString * S)
{
    S->length = 0;
}

_Bool StrEmpty(SString S)
{
    if (S.length == 0)
        return true;
    else
        return false;
}

_Bool SubString(SString * Sub, SString S, int pos, int len)
{
    // 子串范围越界
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos;i<= pos + len -1; i++) {
        Sub->ch[i-pos+1] = S.ch[i];
    }
    Sub->length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

int Index1(SString S, SString T) {
    int i=1, n =StrLength(S), m=StrLength(T);
    SString Sub;
    while ( i<=n-m+1)
    {
        SubString(&Sub, S, i, m);
        if (StrCompare(Sub, T) != 0)  ++i;
        else return i; // 返回子串在主串中的位置
    }
    return 0;
}

int Index2(SString S, SString T) {
    int i=1, j=1;
    while ( i<= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i; ++j; // 继续比较后继字符串
        }
        else {
            i= i-j+2; // 指针到下一个位置
            j= 1; // 指针回退
        }
    }

    if (j>T.length)
        return i-T.length;
    else
        return 0;
}

int Index_KMP(SString S, SString T, int next[])
{
    int i=1, j=1;
    while ( i<= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i; ++j; // 继续比较后继字符串
        }
        else {
            j= next[j];
        }
    }

    if (j>T.length)
        return i-T.length;
    else
        return 0;
}


/**
 * @brief next算法实现
 * 
 */
void GetNext(SString pattern, int next[]) {
    next[0]=-1;
    int i=0, j=-1;
    int pat_leng=StrLength(pattern);
    while (i<pat_leng)
    {
        if (j==-1) {
            i++;
            j++;
        } else if (pattern.ch[i]==pattern.ch[j]) {
            i++;j++;
            next[i]=j;
        } else {
            j = next[j];
        }
    }
};
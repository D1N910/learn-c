#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 255 // 预定串的长度是 255

// 静态数组实现（定长顺序存储）
typedef struct {
    char ch[MAXSIZE]; // 每个分量存储一个字符，系统会自动回收空间
    int length; // 串的实际长度
}SString;

typedef struct StringNode {
    char ch; // 每个节点存1个字符,1b
    struct StringNode * next; // 4个字节存储位置信息
}StringNode, * String; // 【存储密度低】每个字符1b，每个指针4b；

// 解决存储密度低的问题，可以让每个结点存多个字符。存储密度更高
typedef struct StringNode2 {
    char ch[4]; // 每个节点存4个字符,1b
    struct StringNode2 * next; // 4个字节存储位置信息
}StringNode2, * String2;

// 动态数组实现（堆分配存储）
typedef struct {
    char *ch;
    int length; // 串的实际长度
}HString;

int main() {
    HString S;
    S.ch = (char *)malloc(MAXSIZE * sizeof(char)); // 从堆里分配内存，用完需要手动free

    char c[MAXSIZE];
    printf("sizeof c %lu \n", sizeof(char));
    printf("sizeof c %lu \n", sizeof(c)/sizeof(char));
    printf("sizeof c %lu \n", sizeof(HString));
}
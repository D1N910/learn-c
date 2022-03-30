/**
 * @file 2.3.5.0.c
 * @author D1n910 (wyd1n910@gmail.com)
 * @brief 静态链表 p35
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define ElemType int
#define MaxSize 50

typedef struct // 静态链表类型定义
{
    ElemType data; // 存储数据元素
    int next; // 下一个元素的数组下标
} SLinkList[MaxSize];
// 下标为-1则结束

int main(void)
{
}

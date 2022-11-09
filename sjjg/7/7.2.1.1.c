/**
 * @file 7.2.1.1.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 一般线性表的顺序查找 哨兵模式
 * 逐次往前查找，时间复杂度为 O(n)
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MaxSize 50

struct SSTable // 查找表的数据结构
{
    /* data */
    ElemType *elem; //
    int TableLen; // 表的长度 
};

int Search_Seq(struct SSTable, int);

int main() {
    struct SSTable ST;
    ST.elem = (int *)malloc(sizeof(int)*MaxSize);
    ST.TableLen = 10;
    ST.elem[0] = -1;
    for (int i = 1; i<= ST.TableLen; i++)
        ST.elem[i] = i;
    for (int i = 1; i<= ST.TableLen; i++)
        printf("Print data %d > ", ST.elem[i] = i);
    int result;
    
    printf("\n Find data %d \n", 3);
    result = Search_Seq(ST, 3);
    if(result != 0)
        printf("\n Find data %d Success! position is %d \n", 3, result);
    else
        printf("\n Find data Error! \n");

    printf("\n Find data %d \n", 66);

    result = Search_Seq(ST, 66);
    if(result != 0)
        printf("\n Find data %d Success! position is %d \n", 66, result);
    else
        printf("\n Find data Error! \n");
}


int Search_Seq(struct SSTable ST, int key) {
    if (ST.TableLen == 0)
        return 0;
    ST.elem[0] = key;
    int i = ST.TableLen - 1;
    for (;ST.elem[i] != key;){
        i--;
    }
    return i;
}
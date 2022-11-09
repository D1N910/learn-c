/**
 * @file 7.2.2.c
 * @author D1n910 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 二分查找，有序的顺序表
 * 设定工具指针low指向最低位，high指向最高位，mid指向拿来对比的值
 * e.g. 递增的有序表 每轮查找，如果mid对应的值大于查找目标的值，那么说明数据在左边，high=mid-1
 * 若 low > high 则查找失败，返回-1
 * 如果mid对应的值小于查找目标的值，那么说明数据在右边，low=mid+
 * 如果是 mid == (low + high) /2 向下取整，则右子树比左子树多0个或者1个，奇数为0，偶数为1
 * 如果是 mid == (low + high) /2 向上取整，则左子树比右子树多0个或者1个，奇数为0，偶数为1
 * 时间复杂度为判定树树高，如果为n个结点，那么树高为log(2)(n+1)向上取整。时间复杂度为O(log(2)n)
 * 不一定比顺序查找好，比如要查找的元素放在第一位或者最后一位，那么顺序查找一下就找到了；而二分查找要找到最后。
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

int Binary_Search(struct SSTable, int);

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
    result = Binary_Search(ST, 3);
    if(result != 0)
        printf("\n Find data %d Success! position is %d \n", 3, result);
    else
        printf("\n Find data Error! \n");

    printf("\n Find data %d \n", 66);

    result = Binary_Search(ST, 66);
    if(result != 0)
        printf("\n Find data %d Success! position is %d \n", 66, result);
    else
        printf("\n Find data Error! \n");
}


// 返回-1说明没找到
int Binary_Search(struct SSTable L, int key) {
    if (L.TableLen == 0)
        return -1;
    int low = 0, high = L.TableLen - 1, mid ; // 定义工具变量
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == L.elem[mid])
            return mid;
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
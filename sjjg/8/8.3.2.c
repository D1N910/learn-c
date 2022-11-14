/**
 * 
 * @file 快速排序
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdbool.h>

// Partitionn.
// 隔墙，隔板；（国家的）分裂，分治；（化学）分离层；（计算机）存储分区；（数学）分割
// v.
// 分割，分裂（国家）；（用隔板、隔扇等）隔开，分隔
int Partition(int A[], int low, int high);
void QucikSort(int A[], int low, int high);

int main() {
    int A[8] = {49,38,65,97,76,13,27,49};
    QucikSort(A, 8);
    for (int i = 0;i<8;i++)
        printf("%d ", A[i]);
    return 0;
}

void QucikSort(int A[], int low, int high) {
    if (low != high) { //递归跳出的条件
        int pivotpos = Partition(A, low, high); //划分
        QucikSort(A, low, pivotpos - 1); //划分左子表
        QucikSort(A, pivotpos + 1, high); // 划分右子表
    }
}


int Partition(int A[], int low, int high) {
    int pivot = A[low]; //第一个元素作为枢轴
    while (low < high) //用low、high搜索枢轴的最终位置
    {
        while (low<high && A[high] >= pivot) --high; // //比枢轴小的元素移动到左端
        A[low] = A[high];
        while (low<high && A[low] <= pivot) ++high; // 比枢轴大的元素移动到右端
        A[high] = A[low];
    }
    A[low] = pivot; // //枢轴元素存放到最终位置
    return low; //返回存放枢轴的最终位置
}


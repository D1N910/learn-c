#include <stdio.h>
/**
 * @brief 希尔排序
 * 
 * @param A 要排序的数组
 * @param n 数组的长度
 */
void ShellSort (int A[], int n);

int main() {
    int B[9] = {0,49,38,65,97,76,13,27,49};

    ShellSort(B, 9);
    for (int i = 1; i< 9; i++) {
        printf("%d ", B[i]);
    }
}


void ShellSort (int A[], int n) {
    int d,i,j;
    for (d= n/2; d>=1;d = d/2) { // 步长变化，太妙了，用这个就可以相当于多个子表了
        for(i = d+1;i<n;++i){ // d+1 就是留出第一个作为对比，而且后面的都可以和自己“表”的前一个进行对比
            if (A[i]<A[i-d]) { //需将A[i]插入有序增量子表
                // 只是暂存单元，不是哨兵，当j<=0时，插入位置已到
                A[0] = A[i]; //暂存在A[0]
                for (j = i-d;j>0 && A[j] > A[0];j = j-d) {
                    A[j+d] = A[j]; //记录后移，查找插入的位置
                }
                A[j+d] = A[0]; //插入 因为j对应的关键字是不比A[0]大的，而上一次比A关键字大的是j+d
            } // if
        }
    }
}
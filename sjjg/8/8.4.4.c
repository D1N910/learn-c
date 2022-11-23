#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int low, int mid, int high) {
    int *B = (int *)malloc(7*sizeof(int)); // 初始化B数组
    int i,j,k;
    for (k=low;k<=high;k++)
        B[k] = A[k]; // 把A数组的数据拷贝入B数组
    for (i=low, j=mid+1, k=i;i <= mid && j<= high;k++) {
        if (B[i] <= B[j]) {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
    } // for
    // 将剩余的内容合并
    while (i<=mid) A[k++] = B[i++];
    while (j<=high) A[k++] = B[j++];
}


/**
 * @brief 归并排序
 * 
 */
void MergerSort(int A[], int low, int high) {
    if (low < high) { // 最少就是两个
        int mid = (low + high) / 2; // 从中间划分
        MergerSort(A, low, mid); // 对左半边归并排序
        MergerSort(A, mid + 1, high); // 对右半边归并排序
        merge(A, low, mid, high); // 归并
    }
}

int main() {
    int A[7] = {49, 38, 65, 97, 76, 13, 27}; // 其中 串1为 49, 38, 65, 97，串二为 76, 13, 27
    MergerSort(A, 0, 6);
    for (int i = 0;i<=6;i++)
        printf("%d ", A[i]);
    return 0;
}

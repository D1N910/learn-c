/**
 * 
 * @file 简单选择排序
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

/**
 * @brief 选择排序
 * 
 * @param A 数组
 * @param n 数组长度
 */
void SelectSort(int A[], int n);

void swap(int *a, int *b);

int main() {
    int A[8] = {49,38,65,97,76,13,27,49};
    SelectSort(A, 8);
    for (int i = 0;i<8;i++)
        printf("%d ", A[i]);
    return 0;
}

void SelectSort(int A[], int n) {
    for (int i = 0;i < n-1;i++) {
        int min = i;
        for (int j = i+1;j<n;j++) {
            if (A[j]<A[min]) min = j;
        }
        if (min != i) swap(&A[i], &A[min]);
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}




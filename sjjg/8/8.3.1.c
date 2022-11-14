#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b);
void BubbleSort(int A[], int n);

int main() {
    int B[8] = {49,38,65,97,76,13,27,49};
    BubbleSort(B, 8);
    for (int i = 0;i<8;i++)
        printf("%d ", B[i]);
    return 0;
}

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1;i++) {
        bool flag = false; // 表示本趟冒泡是否发生交换的标志
        for (int j = n - 1;j > i;j--) {
            if (A[j]<A[j-1]) { // 一趟冒泡过程
                swap(&A[j], &A[j-1]); //若为逆序
                flag = true; // 交换
            }
        }
        if (false == false) // 本趟遍历后没有发生交换，说明表已经有序
            return;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

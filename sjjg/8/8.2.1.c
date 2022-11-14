#include <stdio.h>
/**
 * @brief 直接插入排序
 * 
 * @param A 要排序的数组
 * @param n 数组的长度
 */
void InsertSort(int A[], int n);

/**
 * @brief 哨兵排序
 * 
 * @param A 要排序的数组
 * @param n 数组的长度
 */
void InsertSortGuard (int A[], int n);

/**
 * @brief 折半插入排序
 * 
 * @param A 要排序的数组
 * @param n 数组的长度
 */
void BinartInsertSort (int A[], int n);

int main() {
    int A[7] = {9,5, 8, 4, 3, 2, 1};
    InsertSort(A, 7);
    for (int i = 0; i<7;i++) {
        printf("%d ", A[i]);
    }

    printf("\n");

    int B[12] = {0,20,30,40,50,60,70,80,
    55,60,90,10};

    BinartInsertSort(B, 12);
    for (int i = 1; i< 12; i++) {
        printf("%d ", B[i]);
    }
}


void BinartInsertSort (int A[], int n) {
    int min, max, mid; // 工具指针
    for (int i = 2; i< n; i++) {
        printf("\nii %d ii\n", i);
        A[0] = A[i]; // 要对比的元素
        if (A[i] < A[i - 1]) {
            printf("\nA[0] %d ii A[0]\n", A[0]);
            for (min = 1,max = i - 1;max > min;) {
                mid = (min + max) / 2;
                printf("\n mid %d A[mid]\n", A[mid]);
                printf("\n A %d A[A]\n", A[0]);
                if (A[mid] > A[0]) {
                    max = mid-1;
                } else {
                    min = mid+1;
                }
            }
            for (int j = i;j>min;j--)
                A[j] = A[j-1];
            A[min] = A[0];
        }
    }
}

void InsertSortGuard(int A[], int n) {
    int i, j;
    for (i = 2;i<n;i++) {
        if (A[i] < A[i-1]) {
            A[0] = A[i]; // 放置哨兵
            for (j = i - 1; A[0] < A[j]; j--)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}

void InsertSort(int A[], int n) {
    int i, j, temp;
    for (i = 1;i<n;i++) {
        if (A[i] < A[i-1]) {
            temp = A[i];
            for (j = i - 1; j >=0 && A[j] > temp; j--)
                A[j+1] = A[j];
            A[j+1] = temp;
        }
    }
}

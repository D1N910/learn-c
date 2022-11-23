#include <stdio.h>

void swap(int *a, int *b);

/**
 * @brief 建立大根堆
 * 
 */
void BuildMaxHeap(int A[], int len);

/**
 * @brief 堆排序
 * 
 */
void HeapSort(int A[], int len);
void HeapSort2(int A[], int len);


/**
 * @brief 将以 k 为根的子树调整为大根堆
 * 
 * @param A 
 * @param k 
 */
void HeadAdjust(int A[], int k, int len);


void BuildMinHeap(int A[], int len);
void HeadAdjust2(int A[], int k, int len);

int main() {
    int A[9] = {-1, 53, 17, 78, 9, 45, 65, 87, 32}; // 下标从1开始
    HeapSort(A, 8);
    for (int i = 1;i<=8;i++)
        printf("%d ", A[i]);

    printf("\n");

    HeapSort2(A, 8);
    for (int i = 1;i<=8;i++)
        printf("%d ", A[i]);

    return 0;
}

// 堆排序的完整逻辑
void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len); // 初始化堆
    for (int i=len;i>1;i--) { //n-1趟的交换和建堆过程
        swap(&A[i], &A[1]); //堆顶元素和堆底元素交换
        HeadAdjust(A, 1, i-1); //把剩余的待排序元素整理成堆
    }
}


// 堆排序的完整逻辑
void HeapSort2(int A[], int len) {
    BuildMinHeap(A, len); // 初始化堆
    for (int i=len;i>1;i--) { //n-1趟的交换和建堆过程
        swap(&A[i], &A[1]); //堆顶元素和堆底元素交换
        HeadAdjust2(A, 1, i-1); //把剩余的待排序元素整理成堆
    }
}

void BuildMaxHeap(int A[], int len) {
    for (int i = len/2; i>0;i--) { // 从后往前调整所有非终端结点
        HeadAdjust(A, i, len);
    }
}

void HeadAdjust(int A[], int k, int len) {
    A[0] = A[k]; // A[0] 暂存子树的根结点
    for (int i = 2*k;i<=len;i*=2) { //沿Key较大的子结点向下筛选
        if (i<len&&A[i]<A[i+1])
            i++; //取key较大的子结点的下标
        if (A[0]>=A[i]) break; // 筛选结束
        else {
            A[k] = A[i]; // 将A[i]调整到双亲结点上
            k = i; // 修改k值，以便继续向下筛选
       }
    }
    A[k] = A[0]; // 被筛选结点的值放入最终位置
}


void BuildMinHeap(int A[], int len) {
    for (int i = len/2;i>0;i--) {
        HeadAdjust2(A, i, len);
    }
}
void HeadAdjust2(int A[], int k, int len) {
    A[0] = A[k]; // A[0]缓存根节点的值
    for (int i = k*2;i<=len;i*=2) {
        if (i<len&&A[i]>A[i+1])
            i++;
        if (A[k]<A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

// 递归调用的方法
void HeadAdjustRecursion(int A[], int k, int len) {
    int maxKey = k; // 记录最大的孩子的下标
    if (len >= 2*k) { // 查看左孩子是否更大
        if (A[2*k]>A[maxKey]) {
            maxKey = 2*k;
        }
    }
    if (len >= 2*k + 1) { // 查看左孩子是否更大
        if (A[2*k+1]>A[maxKey]) {
            maxKey = 2*k + 1;
        }
    }
    if (maxKey != k) {
        int temp = A[k];
        A[k] = A[maxKey];
        A[maxKey] = temp;
        HeadAdjust(A, maxKey, len); // 小的不断下坠
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
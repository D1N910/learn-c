// #include <stdio.h>

// int nums[50];

// int main() {
//     int n; // 数字行数
//     int minIndex; // 最小的值
//     int temp; // 临时数
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &nums[i]);
//     }
//     // 快速排序
//     for (int i = 0; i < n - 1; i++) {
//         minIndex = i;
//         // 找到最小的值对应的下标
//         for (int j = i; j < n; j++) {
//             if (nums[j] < nums[minIndex]) {
//                 minIndex = j; // 替换最小值
//             }
//         }
//         temp = nums[i];
//         nums[i] = nums[minIndex];
//         nums[minIndex] = temp;
//     }
//     for (int i = 0; i < n; i++) {
//         printf("%d", nums[i]);
//         if (i < n - 1) printf(" ");
//     }
//     return 0;
// }

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int a[MAXN], n;

void selectSotr() {
    // 选择排序 简单排序
    for (int i = 0; i < n - 1; i++) {
        int k =  i;
        // 找到最小的值对应的下标
        for (int j = i; j < n; j++) {
            if (a[j] < a[k]) {
                k = j; // 替换最小值
            }
        }
        swap(a[i], a[k]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectSotr();
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    return 0;
}
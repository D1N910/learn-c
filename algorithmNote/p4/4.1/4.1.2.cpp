
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int a[MAXN], n;

void insertSort() {
    // 插入排序
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int  j = i;
        while (j - 1 >= 0 && a[j-1] > temp)
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertSort();
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    return 0;
}
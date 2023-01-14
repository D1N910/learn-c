#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n;
int a[MAXN];

bool cmp(int a, int b) {
    return a>b;
}

// 给定个考生的分数，将它们从高到低排序，然后输出每个分数对应的排名。
void scoreSort() {
    sort(a, a + n, cmp);
}

int main() {
    int degree = 1;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    scoreSort();
    printf("%d %d", a[0], degree);
    for (int i = 1; i < n; i++) {
        printf("\n");
        if (a[i] != a[i-1]) {
            degree = i+1;
        }
        printf("%d %d", a[i], degree);
    }
    return 0;
}

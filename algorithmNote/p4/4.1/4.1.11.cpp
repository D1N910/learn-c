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
    int degree = 0;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    scoreSort();
    int same = 0; // 相同分数的人数
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            printf("%d %d", a[i-1], degree + same);
        } else {
            if (a[i] != a[i-1]) {
                degree += same;
                for (int j = 1; j <= same; j++) {
                    printf("%d %d", a[i-1], degree);
                    if (i <= n - 1) printf("\n");
                }
                same = 1;
            } else {
                same++;
            }
        }
    }
    return 0;
}

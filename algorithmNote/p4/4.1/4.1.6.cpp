#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a.compare(b) > 0;
}

const int MAXN = 50;
int n;
string a[MAXN];

// 顺序
void stringSort() {
    sort(a, a+n, cmp);
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }
    stringSort();
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n;
struct student {
    string name;
    int score;
};

student studentList[MAXN];

bool cmp(student a, student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.name < b.name;
    }
}

// 顺序
void stringSort() {
    sort(studentList, studentList + n, cmp);
}

int main() {
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> studentList[i].name >> studentList[i].score;
    }
    stringSort();
    for (int i = 0; i < n; i++) {
        cout<<studentList[i].name<<" "<<studentList[i].score<<endl;
    }
    return 0;
}

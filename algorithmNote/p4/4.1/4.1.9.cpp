#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int n;
int sortType;
struct student {
    string name;
    int score[2];
};

student studentList[MAXN];

bool cmp(student a, student b) {
    if (sortType <= 2) {
        if (a.score[sortType-1] != b.score[sortType-1]) {
            return a.score[sortType-1] > b.score[sortType-1];
        } else {
            return a.name < b.name;
        }
    } else {
        if (a.score[0] + a.score[1] != b.score[0] + b.score[1]) {
            return a.score[0] + a.score[1] > b.score[0] + b.score[1];
        } else {
            return a.name < b.name;
        }
    }
}

// 顺序
void stringSort() {
    sort(studentList, studentList + n, cmp);
}

int main() {
    cin >> n >> sortType;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> studentList[i].name >> studentList[i].score[0] >> studentList[i].score[1];
    }
    stringSort();
    for (int i = 0; i < n; i++) {
        cout<<studentList[i].name<<" "<<studentList[i].score[0]<<" "<<studentList[i].score[1];
        cout<<" "<<studentList[i].score[0] + studentList[i].score[1]<<endl;
    }
    return 0;
}

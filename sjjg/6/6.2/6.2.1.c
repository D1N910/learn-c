#include <stdio.h>
#define MAXVerterNum 100
#define INFINITY 99999 // 宏定义常量“无穷”
typedef char VertextType; // 顶点元素的类型
typedef int EdgeType; // 带权值边上的数据类型

typedef struct {
    VertextType Vex[MAXVerterNum];
    EdgeType Edge[MAXVerterNum][MAXVerterNum];
    int vexnum,arcnum;
}MGraph;

// 初始化数据
void Init(MGraph *);

int main()
{
    MGraph m;
    Init(&m);
    printf("%d", m.Edge[0][0]);
    return 0;
}

void Init(MGraph *m) {
    for (int i=0;i<MAXVerterNum;i++) {
        for (int j=0;j<MAXVerterNum;j++) {
            m->Edge[i][j] = INFINITY;
        }
    }
}
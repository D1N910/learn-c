#include <stdio.h>
#define INFINITY 99999 // 宏定义常量“无穷”
#define MAXVerterNum 100
typedef char VertextType; // 顶点元素的类型
typedef int EdgeType; // 带权值边上的数据类型

typedef struct ArcNode { // 边表结点
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *next; // 指向下一个弧的指针
    // InfoType info; // 网的边权值
} ArcNode;

typedef struct VNode {
    VertextType data;
    ArcNode *first; // 第一条边
}VNode, AdjList[MAXVerterNum];
typedef struct {
    AdjList vertices; // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph; // 邻接表存储图的类型


int main()
{
    return 0;
}
// 十字链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 99999 // 宏定义常量“无穷”
#define MAXVerterNum 4
typedef int VertextType; // 顶点元素的类型
typedef int EdgeType; // 带权值边上的数据类型

typedef struct ArcNode { // 弧结点
    int tailvex; // 弧尾
    int headvex; // 弧头
    EdgeType info; // 弧的权值
    struct ArcNode *hlink; // 下一个指向相同弧头的弧结点
    struct ArcNode *tlink; // 下一个指向相同弧尾的弧结点
} ArcNode;

typedef struct VNode { // 顶点节点
    VertextType data;
    ArcNode *firstIn; // 第一条以顶点为弧头的弧结点
    ArcNode *firstOut; // 第一条以顶点为弧尾的弧结点
}VNode, OrthogonalList[MAXVerterNum];

typedef struct {
    OrthogonalList vertices; // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} OrthogonalListGraph; // 十字链表法的类型


// 初始化图
void Init(OrthogonalListGraph * g);

/**
 * @brief 结点链接 链接一个头和一个尾
 * 
 * @param g 图
 * @param tail 弧尾
 * @param head 弧头
 */
_Bool LinkV(OrthogonalListGraph * g, int tail, int head);

void GetAllDegree(OrthogonalListGraph, int);

/**
 * @brief 获得出度数量
 * 
 * @param g 
 * @param index 
 * @return int 
 */
int GetOutDegree(OrthogonalListGraph g, int index);

/**
 * @brief 获得入度数量
 * 
 * @param g 
 * @param index 
 * @return int 
 */
int GetInDegree(OrthogonalListGraph g, int index);

int main()
{
    OrthogonalListGraph g;
    Init(&g);

    LinkV(&g, 0, 1); // V1 -> V2
    LinkV(&g, 0, 2); // V1 -> V3
    LinkV(&g, 2, 0); // V3 -> V1
    LinkV(&g, 2, 3); // V3 -> V4
    LinkV(&g, 3, 0); // V4 -> V1
    LinkV(&g, 3, 1); // V4 -> V2
    LinkV(&g, 3, 2); // V4 -> V3

    printf("图总弧数: %d \n", g.arcnum);

    GetAllDegree(g, 0);
    GetAllDegree(g, 1);
    GetAllDegree(g, 2);
    GetAllDegree(g, 3);
    return 0;
}

void Init(OrthogonalListGraph * g) {
    g->vexnum = MAXVerterNum;
    g->arcnum = 0;
    for (int i=0;i<MAXVerterNum-1;i++) {
        g->vertices[i].data = i;
        g->vertices[i].firstIn = NULL;
        g->vertices[i].firstOut = NULL;
    }
}

_Bool LinkV(OrthogonalListGraph * g, int tail, int head) {
    if (tail<0||head<0||tail>MAXVerterNum-1||tail>MAXVerterNum-1) {
        return false;
    }

    // 新建一个弧
    ArcNode * na = (ArcNode *)malloc(sizeof(ArcNode));
    na->tailvex = tail;
    na->headvex = head;
    na->hlink = NULL;
    na->tlink = NULL;
    // 处理弧尾
    if (g->vertices[tail].firstOut == NULL) {
        g->vertices[tail].firstOut = na;
    } else {
        // 当前弧尾结点的最后一个同弧尾的弧
        ArcNode * outLink = g->vertices[tail].firstOut;
        while (outLink->tlink != NULL)
        {
            outLink = outLink->tlink;
        }
        outLink->tlink = na;
        outLink = NULL;
    }

    // 处理弧头
    if (g->vertices[head].firstIn == NULL) {
        g->vertices[head].firstIn = na;
    } else {
        // 当前弧头结点的最后一个同弧头的弧
        ArcNode * headLink = g->vertices[head].firstIn;
        while (headLink->hlink != NULL)
        {
            headLink = headLink->hlink;
        }
        headLink->hlink = na;
        headLink = NULL;
    }

    ++g->arcnum;
    return true;
}

int GetOutDegree(OrthogonalListGraph g, int index) {
    int num = 0;
    ArcNode * p = g.vertices[index].firstOut;

    while (p != NULL)
    {
        num++;
        p = p->tlink;
    }

    return num;
}

int GetInDegree(OrthogonalListGraph g, int index) {
    int num = 0;
    ArcNode * p = g.vertices[index].firstIn;

    while (p != NULL)
    {
        num++;
        p = p->hlink;
    }

    return num;
}

int GetInDegree(OrthogonalListGraph g, int index);

void GetAllDegree(OrthogonalListGraph g, int index) {
    int inNum = GetInDegree(g, index), outNum = GetOutDegree(g, index);
    printf("V%d -- 度：%d;出度：%d;入度：%d; \n", index+1, inNum + outNum, inNum, outNum);
}
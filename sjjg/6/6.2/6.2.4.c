// P203 邻接多重表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 99999 // 宏定义常量“无穷”
#define MAXVerterNum 5
typedef int VertextType; // 顶点元素的类型
typedef int EdgeType; // 带权值边上的数据类型

typedef struct LineNode { // 边结点
    int mark; // 标志域，可用以标记该条边是否被搜索过
    EdgeType info; // 和边相关的各种信息的指针域
    int ivex; // 依附的两个顶点在图中的位置 i
    int jvex; // 依附的两个顶点在图中的位置 j
    struct LineNode *iLink; // 下一个指向相同弧头的弧结点
    struct LineNode *jLink; // 下一个指向相同弧尾的弧结点
} LineNode;

typedef struct VNode { // 顶点节点
    VertextType data;
    LineNode *fitstedge; // 第一条依附的边
}VNode, AdjacencyMultipleTable[MAXVerterNum];

typedef struct {
    AdjacencyMultipleTable vertices; // 邻接多重表
    int vexnum, linenum; // 图的顶点数和边数
} AdjacencyMultipleTableGraph; // 十字链表法的类型


// 初始化图
void Init(AdjacencyMultipleTableGraph * g);

/**
 * @brief 链接两个顶点
 * 
 * @param g 图
 * @param i 相连两个顶点的位置 i
 * @param j 相连两个顶点的位置 j
 */
_Bool LinkV(AdjacencyMultipleTableGraph * g, int i, int j);

void GetAllDegree(AdjacencyMultipleTableGraph, int);

/**
 * @brief 获得出度数量
 * 
 * @param g 
 * @param index 
 * @return int 
 */
int GetOutDegree(AdjacencyMultipleTableGraph g, int index);

/**
 * @brief 获得入度数量
 * 
 * @param g 
 * @param index 
 * @return int 
 */
int GetInDegree(AdjacencyMultipleTableGraph g, int index);

int main()
{
    AdjacencyMultipleTableGraph g;
    Init(&g);
    LinkV(&g, 0, 1);
    LinkV(&g, 0, 3);
    LinkV(&g, 1, 2);
    LinkV(&g, 1, 4);
    LinkV(&g, 2, 3);
    LinkV(&g, 2, 4);
    printf("图总边数: %d \n", g.linenum);

    return 0;
}

void Init(AdjacencyMultipleTableGraph * g) {
    g->vexnum = MAXVerterNum;
    g->linenum = 0;
    for (int i=0;i<MAXVerterNum-1;i++) {
        g->vertices[i].data = i;
        g->vertices[i].fitstedge = NULL;
    }
}

_Bool LinkV(AdjacencyMultipleTableGraph * g, int i, int j) {
    if (i<0||j<0||i>MAXVerterNum-1||j>MAXVerterNum-1) {
        return false;
    }

    // 新建一个边
    LineNode * nl = (LineNode *)malloc(sizeof(LineNode));
    nl->ivex = i;
    nl->jvex = j;
    nl->iLink = NULL;
    nl->jLink = NULL;
    // 处理 i 点
    if (g->vertices[i].fitstedge == NULL) {
        g->vertices[i].fitstedge = nl;
    } else {
        LineNode * nLink = g->vertices[i].fitstedge; // 当前结点
        LineNode * iLink = NULL; // 得到的下一个的节点
        // 找到i的fitstedge上的iLink
        if (nLink->ivex == i) {
            iLink = nLink->iLink;
        } else {
            iLink = nLink->jLink;
        }

        while (iLink != NULL) {
            nLink = iLink;
            if (nLink->ivex == i) {
                iLink = nLink->iLink;
            } else {
                iLink = nLink->jLink;
            }
        }

        if (nLink->ivex == i) {
            nLink->iLink = nl;
        } else {
            nLink->jLink = nl;
        }
        nLink = NULL;
        iLink = NULL;
    }

    ++g->linenum;
    return true;
}
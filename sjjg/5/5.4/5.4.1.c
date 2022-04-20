#include <stdio.h>
#define ElemType int
#define MAX_TREE_SIZE 50

typedef struct {
    ElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode node[MAX_TREE_SIZE]; // 双亲表示
    int n; // 节点数
}PTree;

int main(void) {
    return 0;
}
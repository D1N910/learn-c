//  孩子表示法（顺序存储+链式存储）
#include <stdio.h>
#define ElemType int
#define MAX_TREE_SIZE 50

struct CTNode {
    int child; // 孩子结点在数组中的位置
    struct CTNode *next; // 下一个孩子（相当于是兄弟）
}PTNode;

typedef struct {
    ElemType data;
    struct CTNode *firstChild; // 第一个孩子
}CBox;

typedef struct 
{
    CBox nodes[MAX_TREE_SIZE];
    int n; // 结点的个数和根的位置
};


int main(void) {
    return 0;
}
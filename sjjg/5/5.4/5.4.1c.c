//  孩子表示法（顺序存储+链式存储）
#include <stdio.h>
#define ElemType int
#define MAX_TREE_SIZE 50

struct CSNode {
    ElemType data; // 数据域
    struct CSNode *firstchild,*nextsibling; // 第一个孩子和右兄弟指针
}CSNode, * CSTree;

int main(void) {
    return 0;
}
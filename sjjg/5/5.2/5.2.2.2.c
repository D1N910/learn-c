// 链式存储二叉树
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ElemType
{
    int data;
} ElemType;

typedef struct BiTNode
{
    ElemType value;
    struct BiTNode * lchild, * rchild;
} BiTNode, * BiTree;

int main() {
    BiTree root = NULL;

    root = (BiTree)malloc(sizeof(BiTNode));
    root->value.data = 1;
    root->lchild = NULL;
    root->rchild = NULL;

    BiTNode * p = (BiTree)malloc(sizeof(BiTNode));
    p->value.data = 2;
    p->lchild = NULL;
    p->rchild = NULL;
    
    root->lchild = p;

    printf("%d \n", root->lchild->value.data);

    return 0;
}

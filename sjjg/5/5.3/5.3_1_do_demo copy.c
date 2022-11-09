// 自测用
#include <stdio.h>
#include <stdlib.h>


// 定义二叉树的结点
typedef struct BiTNode
{
    int data; // 存储的值
    struct BiTNode * left;
    struct BiTNode * right;
}BiTNode, *BiTree;

// 初始化树
void IntTree(BiTree *);

// 添加值
void AddValue(BiTree, int);

// 先序遍历
void PreOrder(BiTree);

// 中序遍历
void MidOrder(BiTree);

// 后序遍历
void PostOrder(BiTree);

// 添加值
void AddValue(BiTree, int);

// 获得深度
int TreeDepth(BiTree);

int main(void){
    // 初始化树
    BiTree T = NULL;
    IntTree(&T);
    AddValue(T, 20);
    AddValue(T, 21);
    AddValue(T, 19);
    AddValue(T, 22);
    AddValue(T, 100);
    AddValue(T, 101);
    printf("get data %d \n", T->data);
    printf("get data %d \n", T->left->data);
    printf("get data %d \n", T->right->data);

    // 测试树
    printf("Start Preorder \n");
    PreOrder(T);
    printf("Preorder End \n");

    printf("Start MidOrder \n");
    MidOrder(T);
    printf("MidOrder End \n");

    printf("Start PostOrder \n");
    PostOrder(T);
    printf("PostOrder End \n");

    printf("Depth: %d \n", TreeDepth(T));

    return 0;
}

// 初始化树

// 按照左子树放小值，右子树放大值线索化

// 先序遍历

// 中序遍历

// 后序遍历

// 获得深度
#include <stdio.h>
#include <stdlib.h>


// 定义二叉树的结点
typedef struct BinaryTree
{
    int data; // 存储的值
    struct BinaryTree * left;
    struct BinaryTree * right;
}BinaryTree, *LBinaryTree;

// 初始化树
void IntTree(LBinaryTree *);

// 添加值
void AddValue(LBinaryTree, int);

// 先序遍历
void PreOrder(LBinaryTree);

// 中序遍历
void MidOrder(LBinaryTree);

// 后序遍历
void PostOrder(LBinaryTree);

// 添加值
void AddValue(LBinaryTree, int);

// 获得深度
int TreeDepth(LBinaryTree);

int main(void){
    LBinaryTree T = NULL;
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

    PreOrder(T);
    printf("\n");
    MidOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");

    printf("Depth: %d \n", TreeDepth(T));

    return 0;
}

void IntTree(LBinaryTree *T)
{
    if (*T != NULL) {
        return;
    }
    *T = (LBinaryTree)malloc(sizeof(BinaryTree));
    (*T)->data = -1;
    (*T)->left = NULL;
    (*T)->right = NULL;
}

void AddValue(LBinaryTree T, int x)
{
    if (T == NULL) {
        return;
    }
    if (T->data == -1) {
        T->data = x;
    } else {
        if (x < T->data) {
            IntTree(&(T->left));
            AddValue(T->left, x);
        } else {
            IntTree(&(T->right));
            AddValue(T->right, x);
        }
    }
    return;
}

// 先序遍历
void PreOrder(LBinaryTree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

// 中序遍历
void MidOrder(LBinaryTree T) {
    if (T != NULL) {
        MidOrder(T->left);
        printf("%d ", T->data);
        MidOrder(T->right);
    }
}

// 后序遍历
void PostOrder(LBinaryTree T) {
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d ", T->data);
    }
}

// 获得深度
int TreeDepth(LBinaryTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int l = TreeDepth(T->left);
        int r = TreeDepth(T->right);
        return l > r ? l + 1 : r + 1;
    }
}
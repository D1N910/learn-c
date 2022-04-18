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

// 添加值
void AddValue(LBinaryTree, int);

int main(void){
    LBinaryTree T = NULL;
    IntTree(&T);
    AddValue(T, 20);
    AddValue(T, 21);
    AddValue(T, 19);
    // AddValue(T, 22);
    printf("get data %d \n", T->data);
    printf("get data %d \n", T->left->data);
    printf("get data %d \n", T->right->data);

    PreOrder(T);
    printf("\n");
    MidOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");

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
        PreOrder(T->left);
        printf("%d ", T->data);
        PreOrder(T->right);
    }
}

// 后序遍历
void PostOrder(LBinaryTree T) {
    if (T != NULL) {
        PreOrder(T->left);
        PreOrder(T->right);
        printf("%d ", T->data);
    }
}
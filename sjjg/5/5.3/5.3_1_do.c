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

int main(void){
    LBinaryTree T = NULL;
    IntTree(&T);
    AddValue(T, 20);
    AddValue(T, 21);
    AddValue(T, 19);
    AddValue(T, 22);
    printf("get data %d \n", T->data);
    printf("get data %d \n", T->left->data);
    printf("get data %d \n", T->right->data);
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

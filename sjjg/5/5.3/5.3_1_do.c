#include <stdio.h>
#include <stdlib.h>


// 定义二叉树的结点
typedef struct BinaryTree
{
    int data; // 存储的值
    struct BinaryTree * left, * right;
}BinaryTree, *LBinaryTree;

// 初始化树
void IntTree(LBinaryTree, int x);

// 添加值
void AddValue(LBinaryTree, int);

int main(void){
    BinaryTree T;
    T.data = -1;
    T.left = NULL;
    T.right = NULL;
    AddValue(&T, 20);
    AddValue(&T, 21);
    // AddValue(&T, 22);
    printf("get data %d \n", T.data);
    return 0;
}

void IntTree(LBinaryTree T, int x)
{
    if (T != NULL) {
        printf("IntTree (T != NULL) %d \n", x);
        return;
    }
    printf("IntTree (T == NULL) %d %d \n", T == NULL, x);
    T = (LBinaryTree)malloc(sizeof(BinaryTree));
    T->data = -1;
    T->left = NULL;
    T->right = NULL;
    printf("IntTree (T == NULL) %d %d \n", T == NULL, x);
}

void AddValue(LBinaryTree T, int x)
{
    if (T == NULL) {
        printf("AddValue (T == NULL) %d \n", x);
        return;
    }
    printf("AddValue (T != NULL) %d \n", x);
    printf("AddValue Get Now Data %d \n", T->data);
    if (T->data == -1) {
        T->data = x;
    } else {
        if (x < T->data) {
            printf("x < T.data %d \n", x);
            IntTree(T->left, x);
            AddValue(T->left, x);
        } else {
            printf("x < T.data %d \n", x);
            IntTree(T->right, x);
            printf("x < T.data (T == NULL) %d %d \n", T->right == NULL, x);
            AddValue(T->right, x);
        }
    }
    return;
}

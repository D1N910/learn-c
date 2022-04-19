#include <stdio.h>
#include <stdlib.h>

// 二叉树的结点（链式存储）
typedef struct BiTNode
{
    int data; // 存储的值
    struct BiTNode * lchild, * rchild;
}BiTNode, *BiTree;

// 线索二叉树结点
typedef struct ThreadNode
{
    int data; // 存储的值
    struct ThreadNode * lchild, * rchild;
    int ltag, rtag; // 左右线索标志，当tag位为1的时候才是线索，当tag位为0的时候表示孩子
}ThreadNode, *ThreadTree;

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

// 访问节点
void visit(BiTree);

// 辅助全局变量，用于查找结点p的前驱
BiTNode * p; // p指向目标结点
BiTNode * pre=NULL; // 指向当前访问结点的前驱
BiTNode * final=NULL; // 用于记录最终结果

int main(void){
    BiTree T = NULL;
    IntTree(&T);
    AddValue(T, 20);
    AddValue(T, 21);
    AddValue(T, 19);
    AddValue(T, 22);
    AddValue(T, 100);
    AddValue(T, 101);
    printf("get data %d \n", T->data);
    printf("get data %d \n", T->lchild->data);
    printf("get data %d \n", T->rchild->data);

    PreOrder(T);
    printf("\n");
    MidOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");

    printf("Depth: %d \n", TreeDepth(T));

    return 0;
}

void IntTree(BiTree *T)
{
    if (*T != NULL) {
        return;
    }
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = -1;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}

void AddValue(BiTree T, int x)
{
    if (T == NULL) {
        return;
    }
    if (T->data == -1) {
        T->data = x;
    } else {
        if (x < T->data) {
            IntTree(&(T->lchild));
            AddValue(T->lchild, x);
        } else {
            IntTree(&(T->rchild));
            AddValue(T->rchild, x);
        }
    }
    return;
}

// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
       visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void MidOrder(BiTree T) {
    if (T != NULL) {
        PreOrder(T->lchild);
       visit(T);
        PreOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
       visit(T);
    }
}

// 获得深度
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        return l > r ? l + 1 : r + 1;
    }
}

// 访问结点q
void visit(BiTree q) {
    if (q == p) // 当前访问的结点刚好是结点P
        final = pre; // 找到p的前驱
    else
        pre = q; // pre 只指向当前的结点
    printf("%d ", q->data);
}
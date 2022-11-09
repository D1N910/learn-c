#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 第二轮强化手打

// 定义二叉树的结点
typedef struct BiTNode
{
    int data; // 存储的值
    struct BiTNode * lchild;
    struct BiTNode * rchild;
}BiTNode, *BiTree;

// 链式队列的结点
typedef struct LinkNode
{
    BiTNode * data;
    struct LinkNode * next;
} LinkNode;

typedef struct LinkQueue
{
    LinkNode *front, *last; // 定义队头和队尾
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue);
// 入队列
void EnQueue(LinkQueue *, BiTree);
// 出队列
void DeQueue(LinkQueue *, BiTree *);
// 判断队列是否为空
_Bool isEmpty(LinkQueue);

LinkQueue Q;

// 初始化树
void InitTree(BiTree *);

// 添加值
void AddValue(BiTree, int);

// 先序遍历
void PreOrder(BiTree);

// 中序遍历
void MidOrder(BiTree);

// 后序遍历
void PostOrder(BiTree);

// 层次遍历
void LevelOrder(BiTree);

// 添加值
void AddValue(BiTree, int);

// 获得深度
int TreeDepth(BiTree);

// 访问元素
void Visit(BiTree);

int main(void){
    // 初始化树
    BiTree T = NULL;
    InitTree(&T);
    AddValue(T, 20);
    AddValue(T, 21);
    AddValue(T, 19);
    AddValue(T, 22);
    AddValue(T, 100);
    AddValue(T, 101);

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

    printf("Start LevelOrder \n");
    LevelOrder(T);
    printf("LevelOrder End \n");

    return 0;
}

// 初始化树
void InitTree(BiTree * T) {
    if (*T != NULL)
        return;
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = -1;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}

// 按照左子树放小值，右子树放大值线索化
void AddValue(BiTree T, int x) {
    if (T->data == -1) {
        T->data = x;
    } else if ( x < T->data) {
        InitTree(&T->lchild);
        AddValue(T->lchild, x);
    } else if ( x > T->data) {
        InitTree(&T->rchild);
        AddValue(T->rchild, x);
    } else {
        printf("Error! Have Same Number!");
    }
}

// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
};

// 中序遍历
void MidOrder(BiTree T) {
    if (T != NULL) {
        MidOrder(T->lchild);
        Visit(T);
        MidOrder(T->rchild);
    }
};

// 后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
};

// 获得深度
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int x = TreeDepth(T->lchild);
    int y = TreeDepth(T->rchild);
    return (x > y ? x : y) + 1;
}

// 访问元素
void Visit(BiTree T) {
    if (T != NULL)
        printf("%d ", T->data);
}

void LevelOrder(BiTree T) {
    // 初始化队列
    InitQueue(Q);
    // 工具指针
    BiTree P;
    // 入队
    EnQueue(&Q, T);
    while (!isEmpty(Q))
    {
        // 出队
        DeQueue(&Q, &P);
        // 访问元素
        Visit(P);
        // 如果有左孩子，入队列；
        if (P->lchild != NULL)
            EnQueue(&Q, P->lchild);
        // 如果有右孩子，入栈；
        if (P->rchild != NULL)
            EnQueue(&Q, P->rchild);
    }
    
}

/** 功能代码 */
// 初始化队列
void InitQueue(LinkQueue Q) {
    Q.front = NULL;
    Q.last = NULL;
}

// 入队列
void EnQueue(LinkQueue * Q, BiTree T) {
    LinkNode * p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = T;
    p->next = NULL;
    if (isEmpty(*Q)) {
        Q->front = p;
        Q->last = p;
    } else {
        Q->last->next = p;
        Q->last = p;
    }
}

// 出队列
void DeQueue(LinkQueue * Q, BiTree *T)  {
    if (isEmpty(*Q)) {
        return;
    } else {
        LinkNode * p = Q->front;
        Q->front = p->next;
        *T = p->data;
        free(p);
        // 如果队头指向是NULL了
        if (Q->front == NULL)
            Q->last = NULL;
    }
}
// 判断队列是否为空
_Bool isEmpty(LinkQueue Q) {
    return Q.front == NULL;
}
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
void BST_Insert(BiTree, int);

// 先序遍历
void PreOrder(BiTree);

// 中序遍历
void MidOrder(BiTree);

// 后序遍历
void PostOrder(BiTree);

// 层次遍历
void LevelOrder(BiTree);

// 添加值
void BST_Insert(BiTree, int);

// 获得深度
int TreeDepth(BiTree);

// 访问元素
void Visit(BiTree);

// 在二叉排序树中查找值为 key 的结点
BiTree BSTSearch(BiTree, int key);

// 删除对应的值
_Bool BSTDelete(BiTree *, int key);

// 删除测试
void testDelete(int key);

int main(void){
    testDelete(5);
    testDelete(2);
    testDelete(4);
    testDelete(78);
    testDelete(79);
    testDelete(76);
    return 0;
}

void testDelete(int key) {
    // 初始化树
    BiTree T = NULL;
    InitTree(&T);
    BST_Insert(T, 5);
    BST_Insert(T, 3);
    BST_Insert(T, 78);
    BST_Insert(T, 75);
    BST_Insert(T, 100);
    BST_Insert(T, 79);
    BST_Insert(T, 4);
    BST_Insert(T, 2);
    // 测试树
    printf("Start MidOrder \n");
    MidOrder(T);
    printf("MidOrder End \n");

    printf("You want to delete %d \n", key);

    bool result = BSTDelete(&T, key);
    if (result) {
        printf("Delete Success!!!\n");
        // 测试树
        printf("MidOrder:\n");
        MidOrder(T);
        printf("PostOrder:\n");
        PostOrder(T);
        printf("\n End \n\n");
    } else {
        printf("\n!!!Delete Error!!!\n\n");
    }
}

// 测试查找值
void test1() {
    // 初始化树
    BiTree T = NULL;
    InitTree(&T);
    BST_Insert(T, 20);
    BST_Insert(T, 21);
    BST_Insert(T, 19);
    BST_Insert(T, 22);
    BST_Insert(T, 100);
    BST_Insert(T, 101);

    // 查找值测试
    BiTree TSearch = BSTSearch(T, 101);
    if (TSearch != NULL)
        printf("Search Success! %d \n", TSearch->data);
    else
        printf("Search Fail! \n");
    TSearch = BSTSearch(T, 102);
    if (TSearch != NULL)
        printf("Search Success! %d \n", TSearch->data);
    else
        printf("Search Fail! \n");
}

BiTree BSTSearch(BiTree T, int key) {
    if (T == NULL)
        return NULL;
    while (T != NULL)
    {
        if (T->data == key)
        {
            return T;
        } else if (T->data < key)
        {
            T = T->rchild;
        } else {
            T = T->lchild;
        }
        
    }
    return NULL;
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

// 按照左子树放小值，右子树放大值线索化-非递归实现
void BST_Insert(BiTree T, int x) {
    if (T->data == -1) {
        T->data = x;
    }
    while (T != NULL)
    {
        /* code */
        if ( x < T->data) {
            if (T->lchild == NULL) {
                InitTree(&T->lchild);
                T->lchild->data = x;
                break;
            }
            T = T->lchild;
        } else if ( x > T->data) {
            if (T->rchild == NULL) {
                InitTree(&T->rchild);
                T->rchild->data = x;
                break;
            }
            T = T->rchild;
        } else {
            printf("Error! Have Same Number!");
            return;
        }
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

_Bool BSTDelete(BiTree * T, int key) {
    BiTree p; // 工具指针
    BiTree pPre; // 工具指针,存父节点
    if (*T == NULL) {
        return false;
    }
    // 情况一，没有匹配上
    if ((*T)->data != key) {
        if (key < (*T)->data) {
            return BSTDelete(&((*T)->lchild), key);
        } else {
            return BSTDelete(&((*T)->rchild), key);
        }
    }
    // 情况一，没有头结点的树，匹配上，是叶子节点
    if ((*T)->lchild == NULL && (*T)->rchild == NULL) {
        free(*T);
        *T = NULL; // 指针置为空
        return true;
    }
    // 情况二-a，没有头结点的树，匹配上，只有左子树
    if ((*T)->lchild != NULL && (*T)->rchild == NULL) {
        p = *T; // 工具指针存储原地址
        *T = p->lchild;
        free(p); // 释放空间
        return true;
    }
    // 情况二-b，没有头结点的树，匹配上，只有右子树
    if ((*T)->rchild != NULL && (*T)->lchild == NULL) {
        p = *T; // 工具指针存储原地址
        *T = p->rchild;
        free(p); // 释放空间
        return true;
    }
    // 情况三-b，没有头结点的树，匹配上，有左右子树，让直接后继，右子树的最左下角继承自己的位置
    pPre = (*T);
    p = (*T)->rchild;
    while (p->lchild != NULL)
    {
        pPre = p; // 记录直接后继的父节点
        p = p->lchild;
    } // while 遍历找到直接后继
    (*T)->data = p->data; // 值替换
    // 如果没有右孩子
    if (p->rchild == NULL) {
        pPre->lchild = NULL; // 结点置空
        free(p); // 释放
    } else {
        pPre->lchild = p->rchild; // 右孩子上位
        free(p); // 释放
    }
    return true;
}
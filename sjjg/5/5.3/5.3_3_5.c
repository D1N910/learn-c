#include <stdio.h>
#include <stdlib.h>

// 线索二叉树结点
typedef struct ThreadNode
{
    int data; // 存储的值
    struct ThreadNode * lchild, * rchild;
    int ltag, rtag; // 左右线索标志，当tag位为1的时候才是线索，当tag位为0的时候表示孩子
}ThreadNode, *ThreadTree;

// 初始化树
void IntTree(ThreadTree *);

// 添加值
void AddValue(ThreadTree, int);

// 先序遍历
void PreOrder(ThreadTree);


// 中序线索化二叉树
void CreateInThread(ThreadTree);

// 中序遍历
void InThread(ThreadTree);

// 后序遍历
void PostOrder(ThreadTree);

// 添加值
void AddValue(ThreadTree, int);

// 获得深度
int TreeDepth(ThreadTree);

// 访问节点
void visit(ThreadTree);

// 辅助全局变量，用于查找结点p的前驱
ThreadNode * p; // p指向目标结点
ThreadNode * pre=NULL; // 指向当前访问结点的前驱
ThreadNode * final=NULL; // 用于记录最终结果

int main(void){
    ThreadTree T = NULL;
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
    InThread(T);
    printf("\n");
    PostOrder(T);
    printf("\n");

    printf("Depth: %d \n", TreeDepth(T));

    return 0;
}

void IntTree(ThreadTree *T)
{
    if (*T != NULL) {
        return;
    }
    *T = (ThreadTree)malloc(sizeof(ThreadNode));
    (*T)->data = -1;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}

void AddValue(ThreadTree T, int x)
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

// 中序线索化二叉树
void CreateInThread(ThreadTree T) {
    pre = NULL;
    InThread(T);
    if (pre!= NULL&&pre->rchild==NULL) {
        pre->rtag = 1;
    }
}

// 找到以p为根的子树中，第一个被中序遍历的节点
ThreadNode *FirstNode(ThreadNode *p) {
    // 循环找到最左下节点，不一定是叶子节点)
    while (p->ltag == 0) p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p) {
    if (p->rtag == 0) return FirstNode(p);
    else return p->rchild; // rtag == 1 直接返回右结点
}

// 对中序线索二叉树进行中序遍历 todo 是不是搞错了
void InThreadNext(ThreadTree T) {
    for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p)) {
        visit(p); // 访问结点
    }
}

// 中序遍历，一边遍历一边线索化，不会有转圈圈问题
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

// 先序遍历，会有转圈圈问题
void PreOrder(ThreadTree T) {
    if (T != NULL) {
        visit(T);
        if (T->ltag == 0)
            PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 后序遍历，不会有转圈问题
void PostOrder(ThreadTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 获得深度
int TreeDepth(ThreadTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        return l > r ? l + 1 : r + 1;
    }
}

// 访问结点q
void visit(ThreadTree q) {
    if (q->lchild == NULL) { // 左子树为空，那么指向前驱
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre!=NULL&&pre->rchild==NULL) {
        pre->rchild = q; // 建立前驱结点的后继搜索
        pre->rtag = 1;
    }
    pre = q; // pre 只指向当前的结点
    printf("%d ", q->data);
}
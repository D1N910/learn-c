#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElementType int
typedef struct LinkNode // 链式队列节点
{
    ElementType data;
    struct LinkNode* next;
} LinkNode;

typedef struct // 链式队列
{
    LinkNode *front,*rear; // 队列队头和队尾节点
}ListQueue;

/**
 * @brief 初始化队列（带头结点）
 * 
 * @param Q 
 */
void InitQueue(ListQueue *Q);

/**
 * @brief 入队，将x加入
 * 
 * @param Q 
 * @param x 
 */
void EnQueue(ListQueue *, ElementType);

/**
 * @brief 出队，若队列Q非空，删除队头元素，并用x返回
 * 
 * @param Q 
 * @param x 
 * @return _Bool 
 */
_Bool DeQueue(ListQueue *Q, ElementType *x);

/**
 * @brief 读队头元素，若队列Q非空，则将队头元素赋值给x
 * 
 * @param Q 
 * @param x 
 * @return _Bool 
 */
_Bool GetHead(ListQueue Q, ElementType *x);

/**
 * @brief 判队列空，若队列Q为空返回true，否则返回false
 * 
 * @param Q 
 * @return _Bool 
 */
_Bool QueueEmpty(ListQueue Q);

int main(void)
{
    ListQueue Q;
    

    return 0;
}

void InitQueue(ListQueue *Q)
{
    Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode)); // 头节点
    Q->front = NULL;
    /**
     * @brief 初始化不带头结点
     * Q->front = NULL;
     * Q->rear = NULL;
     */
}

void EnQueue(ListQueue *Q, ElementType x)
{
    // 带头结点入队
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); // 头节点
    s->data = x;
    s->next = NULL;
    Q->rear->next = s; // 新结点插入到 rear 之后
    Q->rear = s; // 修改表尾指针
    /**
     * @brief 不带头结点入队
     *  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); // 头节点
     * s->data = x;
     * s->next = NULL;
     * if (Q->front == NULL) { // 在空队列中插入一个新元素
     *   Q->front = s;
     *   Q->rear = s;
     * } else {
     *   Q->rear->next = s;
     *   Q->rear = s;
     * }
     * 
     */
}

_Bool DeQueue(ListQueue *Q, ElementType *x)
{
    // 带头结点出队
    if (QueueEmpty(*Q)) {
        return false; // 空队
    }
    LinkNode *p = Q->front->next;
    x = p->data; // 用变量 x 返回队头元素
    Q->front->next = p->next;   // 修改头结点的 next 指针
    if (Q->rear == p) { //此次是最后一个节点出队
        Q->rear = Q->front; // 修改 rear 指针
    }
    free(p); // 释放结点空间
    return true;
}

_Bool NoHeadDeQueue(ListQueue *Q, ElementType *x)
{
    // 不带头结点出队
    if (QueueEmpty(*Q)) {
        return false; // 空队
    }
    LinkNode *p = Q->front;
    x = p->data; // 用变量 x 返回队头元素
    Q->front = p->next;   // 修改头结点的 next 指针
    if (Q->rear == p) { //此次是最后一个节点出队
        Q->front = NULL; // front 指向 NUll
        Q->rear = NULL; // rear 指向 NUll
    }
    free(p); // 释放结点空间
    return true;
}

_Bool GetHead(ListQueue Q, ElementType *x)
{
    if (Q.front->next == NULL) {
        return false;
    }
    x = Q.front->next->data;
    return true;
}


_Bool QueueEmpty(ListQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}
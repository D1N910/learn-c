#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10
#define ElementType int

typedef struct Queue
{
    ElementType data[MaxSize]; // 数据
    int front, rear; // 队头指针和队尾指针
} SqQueue;

// rear n.后面；后方部队；屁股 adj.后方的，后面的；背面的
// front n.前面；正面；前线 vt.面对；朝向；对付 vi.朝向 adj.前面的；正面的

/**
 * @brief 初始化队列
 * 
 * @param Q 
 */
void InitQueue(SqQueue *Q);

/**
 * @brief 判队列空，若队列Q为空返回true，否则返回false
 * 
 * @param Q 
 * @return _Bool 
 */
_Bool QueueEmpty(SqQueue Q);

/**
 * @brief 销毁队列，销毁并释放队列Q所占用的内存空间
 * 
 * @param Q 
 */
void DestroyQueue(SqQueue *Q);

/**
 * @brief 入队，若队列Q未满，将x加入，使之成为新的队尾
 * 
 * @param Q 
 * @param x 
 * @return _Bool 
 */
_Bool EnQueue(SqQueue *Q, ElementType x);

/**
 * @brief 出队，若队列Q非空，删除队头元素，并用x返回
 * 
 * @param Q 
 * @param x 
 * @return _Bool 
 */
_Bool DeQueue(SqQueue *Q, ElementType *x);

/**
 * @brief 读队头元素，若队列Q非空，则将队头元素赋值给x
 * 
 * @param Q 
 * @param x 
 * @return _Bool 
 */
_Bool GetHead(SqQueue Q, ElementType *x);

/**
 * @brief 判断队列长度
 * 
 * @param Q 
 * @param x 
 */
int GetQueueLength(SqQueue Q);

int main(void)
{
    SqQueue Q;
    int x;
    InitQueue(&Q);
    printf("Q->front %d\n", Q.front);
    EnQueue(&Q, 2);
    EnQueue(&Q, 4);
    EnQueue(&Q, 6);
    EnQueue(&Q, 7);
    EnQueue(&Q, 8);
    EnQueue(&Q, 10);
    GetHead(Q, &x);
    printf("GetHead 1 %d\n", x);
    GetHead(Q, &x);
    printf("GetHead 2 %d\n", x);
    printf("Queue Length %d\n", GetQueueLength(Q));
    DeQueue(&Q, &x);
    printf("DeQueue 1 %d\n", x);
    printf("Queue Length %d\n", GetQueueLength(Q));
    DeQueue(&Q, &x);
    printf("DeQueue 2 %d\n", x);
    printf("Queue Length %d\n", GetQueueLength(Q));
    DeQueue(&Q, &x);
    printf("DeQueue 3 %d\n", x);
    printf("Queue Length %d\n", GetQueueLength(Q));
    return 0;
}

void InitQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
}

_Bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}

_Bool EnQueue(SqQueue *Q, ElementType x) {
    if ((Q->rear + 1) % MaxSize == Q->front) {
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize; // 队尾指针加1取模
    /**
     * @brief 循环队列
     * 用模运算将存储空间在逻辑上变成了“环装”
     */
    return true;
}

_Bool DeQueue(SqQueue *Q, ElementType *x) {
    if (QueueEmpty(* Q)) {
        return false;
    }
    *x = Q->data[Q->front]; // 赋值
    Q->front = (Q->front + 1) % MaxSize; // 队头指针加1取模
    return true;
}

_Bool GetHead(SqQueue Q, ElementType *x) {
    if (QueueEmpty(Q)) {
        return false;
    }
    *x = Q.data[Q.front]; // 赋值
    return true;
}

void DestroyQueue(SqQueue *Q) {
   InitQueue(Q);
    /**
     * @brief todo 如何销毁数组的内存
     * 
     */
}

int GetQueueLength(SqQueue Q) {
    return (Q.rear+MaxSize-Q.front)%MaxSize;
}

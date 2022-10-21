/**
 * @file 3.2.2_2.c 队列-循环队列-队尾元素指向下一元素
 * @author D1n910
 * @brief 
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 1、队列顺序存储数据结构 done
 * 2、初始化队列 done
 * 3、入队列
 * 4、出队列
 * 5、对列判空
 * 6、队列判满
 * 
 */
#include <stdio.h>
#include <stdbool.h>

#define ElemType int
#define MaxSize 10

typedef struct Queue {
    ElemType data[MaxSize];
    int front, rear;
} Queue;

/**
 * @brief 2、初始化队列 
 * 
 * @param
 * 
 */
Queue InitQueue() {
    Queue Q;
    Q.front = 0; // 初始化队首队尾元素
    Q.rear = 0;// 初始化队首队尾元素
    return Q;
}


// 入队操作（循环队列）
_Bool EnQueue(Queue *Q, int x) {
    if ((Q->rear+1 % MaxSize) == Q->front) //队满则报错
        return false;
    
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1) % MaxSize;
    return true;
}

// 出队操作
_Bool DeQueue(Queue *Q, int * x) {
    if (Q->front == Q->rear) // 判断是否是满的
        return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front+1) % MaxSize; // 队头指针+1取模
    return true;
}

// 判断队列为空 true 为空，false 为非空
_Bool isEmpty(Queue Q) {
    return Q.front == Q.rear;
}

// 判断队满
_Bool isFull(Queue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}


int main()
{
    Queue Q = InitQueue();
    printf("%d \n", Q.rear);
    if (isEmpty(Q))
        printf("Empty!\n");
    else {
        printf("No Empty! \n");
    }
    printf("\n******** TEST ********\n");
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    int x;
    DeQueue(&Q, &x);
    printf("%d ", x);
    DeQueue(&Q, &x);
    printf("%d ", x);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    EnQueue(&Q, 4);
    if (isFull(Q))
        printf("Full!\n");
    else {
        printf("No Full! \n");
    }
    EnQueue(&Q, 4);
    if (isFull(Q))
        printf("Full!\n");
    else {
        printf("No Full! \n");
    }
    return 0;
}


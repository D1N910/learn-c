/**
 * @file 2.2.3.c 单链表-按序号查找结点值、按值查找表节点
 * @author D1n910 (260002330@qq.comss)
 * @brief 单链表的实现
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define my_printf(s) (printf(#s " %d \n", s))
#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *ListNode;

ListNode my_L;

/**
 * @brief 尾插法
 * 
 * @param L 
 * @return ListNode 
 */
ListNode List_initTail(ListNode L);

/**
 * @brief 按序号查找表节点
 * 
 * @param L 
 * @return ListNode 
 */
LNode *GetElem(ListNode L, int index);

/**
 * @brief 按值查找表节点
 * 
 * @param L 
 * @param e 
 * @return LNode* 
 */
LNode *LocateElem(ListNode L, ElemType e);

/**
 * @brief 获取表的长度
 * 
 * @param L 
 * @return L.Length 
 */
int GetLLength(ListNode L);

/**
 * @brief 操作列表
 * 
 * @param operate_serialNumber 
 */
void OperateList();

int main(void)
{
    my_L = (ListNode)malloc(sizeof(LNode));
    my_L->next = NULL;

    OperateList();

    return 0;
}

ListNode List_initTail(ListNode L)
{
    int e; // 获取的数字内容
    L = (ListNode)malloc(sizeof(LNode));
    LNode *s; // 新节点的内容
    LNode *r = L; // 表尾指针

    printf("Please enter number(enter 9999 mean terminate input):");
    scanf("%d", &e); // 输入第一个节点的值

    while (e != 9999)
    {
        s = (ListNode)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;
        r = s;
        printf("Please enter number(enter 9999 mean terminate input):");
        scanf("%d", &e);
    };
    r->next = NULL; // 尾指针为空
    return L;
}


LNode *GetElem(ListNode L, int index)
{
    LNode *e = L->next; // 找到的点
    int j = 1; // 点
    if (index == 0)
        return L; // 若 i 等于 0，则返回头结点
    if (index < 1)
        return NULL; // 若 i 无效，返回 NULL
    while (e && j < index) // 从第一个节点找，查找第 index 个节点
    {
        /* code */
        e = e->next;
        j++;
    }

    return e; // 返回元素，如果没找到，那么就是 NULL
}

int GetLLength(ListNode L)
{
    int i = 0;
    LNode *e = L->next;
    while (e)
    {
        e = e->next;
        i++;
    }
    return i;
}

LNode *LocateElem(ListNode L, ElemType e)
{
    ListNode p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }

    return  p;
}

void OperateList(void)
{
    int my_L_length; // 长度
    LNode *search_data;
    int next_number;

    printf("What you want to do: \n"
        "Use tail insert to init list[Enter number '1'] \n"
        "Get list's length[Enter number '2'] \n"
        "Search one data use index[Enter number '3'] \n"
        "Search one data equal data[Enter number '4'] \n"
        "Quit[Enter number '0'] \n"
    );
    
    scanf("%d", &next_number);

    switch (next_number)
    {
        case 0:
            exit(0); // 退出
            break;
        case 1:
            my_L = List_initTail(my_L);
        break;
        case 2:
            printf("Start 'GetLLength'\n");
            my_L_length = GetLLength(my_L);
            printf("List's length is %d \n", my_L_length);
        break;
        case 3:
            printf("Which element do you want to get the data for：");
            scanf("%d", &next_number);
            search_data = GetElem(my_L, next_number);
            if (search_data) {
                printf("Successfully found data: %d !!!\n", search_data->data);
            } else {
                printf("\n\nWorry! Please check your enter data! \n\n");
            }
        break;
        case 4:
            printf("You want to check the data:");
            scanf("%d", &next_number);
            search_data = LocateElem(my_L, next_number);
            if (search_data) {
                printf("Successfully found data: %d !!!\n", search_data->data);
            } else {
                printf("\n\nWorry! We do not have '%d'! \n\n", next_number);
            }
        break;

        default:
            OperateList();
        break;
    }

    OperateList();
}
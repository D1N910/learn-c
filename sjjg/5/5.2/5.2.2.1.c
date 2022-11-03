// 定义一个满二叉树，完全二叉树的顺序存储
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100
#define ElemType int
struct TreeNode
{
    ElemType value;
    _Bool isEmpty; 
};

struct TreeNode t[MaxSize];


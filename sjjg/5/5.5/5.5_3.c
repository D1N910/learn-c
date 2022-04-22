/**
 * @file 5.5_2.c 并查集
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#define SIZE 13 //集合

int UFSets[SIZE]; // 集合元素数组

// 初始化
void Initial(int S[]) {
    for (int i=0;i<SIZE;i++) {
        S[i] = -1;
    }
}

// 查 找根
int Find(int S[], int x) {
    while (S[x] > 0) // 循环找到x的根
    {
        x = S[x];
    }
    return x;
}

// 查 找根 压缩路径 视频方法
int FindCompressPath(int S[], int x) {
    int root = x;
    while (S[root] > 0)  root = S[root];// 循环找到x的根
    if (root != x) {
        while (S[x] > 0) {
            int t = S[x]; // 指向父节点
            S[x] = root; // x 直接挂到节点下
            x = t; // x指向父
        }
    }
    return root;
}

// 查 找根 压缩路径，自己的方法
int FindBetterM(int S[], int x) {
    if (S[x] < 0) return x;
    S[x] = FindBetterM(S, S[x]);
    return S[x];
}

// 并 合并指定的集合
void Union(int S[], int Root1, int Root2) {
    // 相同根不连接
    if (Root1 == Root2) return;
    // 将根连接到另一个绝对值更大的根下面
    if (-S[Root2] < -S[Root1]) {
        S[Root1] += S[Root2]; // 累加结点数
        S[Root2] = Root1; // 小树合并大树
    }
    else {
        S[Root2] += S[Root1]; // 累加结点数
        S[Root1] = Root2; // 小树合并大树
    }
}

// 初始化并查集

int main(void)
{
    return 0;
}


// #define MAX_TREE_SIZE 100 //集合
// #define ElementType int

// typedef struct { // 树的结点定义
//     ElementType data; // 数据元素
//     int parent; // 双亲位置域
// }PTNode; // 结点

// typedef struct{ // 树的类型定义
//     PTNode nodes[MAX_TREE_SIZE]; // 双亲表示
//     int n; // 结点数
// }PTree; // 集合
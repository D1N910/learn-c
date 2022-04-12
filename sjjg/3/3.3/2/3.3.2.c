#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "strack.c"
/**
 * @brief 比较运算符优先级
 * 右值（横排）比左值（竖排）优先级相同或者更高的为 1
 * 右值比左值优先级低的为 0
 * 无法比较的为 -1
 * 
 * @param index1 
 * @param index2 
 * @return int 
 */
int getPriority(int index1, int index2);

/**
 * @brief 获得运算符对应的序号
 * 
 * @param c 
 * @return int 
 */
int getIndex(char c);

void calculate(Strack *, char);

int main(void)
{
    Strack operatorStack; // 运算符栈
    Strack operationCountStack; // 操作数栈
    char result; // 结果

    // 初始化栈
    InitStrack(&operatorStack);
    InitStrack(&operationCountStack);

    // 中缀表达式 ((15/(7-(1+1)))*3)-(2+(1+1))
    char operation[][10] = {"(", "(", 15, "/", "(", 7, "-", "(", 1, "+", 1, ")", ")", ")", "*", 3, ")", "-", "(", 2, "+", "(" , "1", "+", "1", ")", ")", "#"};
    int i = 0;
    while (strcmp(operation[][i], )) // 当不是最后一位时
    {
        i++;
        int getIndexOperation = getIndex(operation[i]);
        if (getIndexOperation == 7) { // 当是数字时，直接入操作数栈
            EnStrack(&operationCountStack, operation[i]);
        } else if (getIndexOperation){ // 当不是数字时
            if (getIndexOperation == 4) { // 如果是左括号，那么存储入运算符栈
                EnStrack(&operatorStack, operation[i]);
            } else if (getIndexOperation == 5) { // 如果是右括号，那么依次弹出直到左括号
                char operator; // 运算符
                OutStrack(&operatorStack, &operator); // 获得下一个运算符
                while (getIndex(operator) != 4 && ifStrackEmpty(operatorStack)) {
                    calculate(&operationCountStack, operator); // 计算
                    OutStrack(&operatorStack, &operator); // 获得下一个运算符
                }
            } else {
                char topOperator; // 运算符
                _Bool getTopStrackSuccess = getTopStrack(operatorStack, &topOperator); // 获得栈顶运算符进行比较
                while (getPriority(getIndexOperation, getIndex(topOperator)) == 1 && getTopStrackSuccess) {
                    char operator; // 运算符
                    OutStrack(&operatorStack, &operator); // 获得下一个运算符进行运算
                    calculate(&operationCountStack, operator); // 计算
                    getTopStrackSuccess = getTopStrack(operatorStack, &topOperator); // 获得栈顶运算符进行比较
                }
                EnStrack(&operatorStack, operation[i]); // 运算符压栈
            }
        }
    }
    getTopStrack(operatorStack, &result);
    printf("计算结束，结果为%d\n", (int)result);
    return 0;
}

void calculate(Strack *operationCountStack, char operator) {
        char leftNumber;
        char rightNumber;
        float sum;
        OutStrack(operationCountStack, &rightNumber); // 右操作数
        OutStrack(operationCountStack, &leftNumber); // 左操作数
        sum = (float)leftNumber + (float)rightNumber; // 计算
        switch (operator)
        {
        case '+':
            sum = (float)leftNumber + (float)rightNumber;
            break;
        case '-':
            sum = (float)leftNumber - (float)rightNumber;
            break;
        case '*':
            sum = (float)leftNumber * (float)rightNumber;
            break;
        case '/':
            sum = (float)leftNumber / (float)rightNumber;
            break;
        default:
            break;
        }
        EnStrack(operationCountStack, (char)sum); // 入栈
}

int getIndex(char c) {
    switch (c)
    {
        case '+':
            return 0;
        break;
        case '-':
            return 1;
        break;
        case '*':
            return 2;
        break;
        case '/':
            return 3;
        break;
        case '(':
            return 4;
        break;
        case ')':
            return 5;
        break;
        case '#':
            return 6;
        break;
        default:
            return 7;
        break;
    }
    return 0;
}

int getPriority(int index1, int index2) {
    // + - * / ( ) #
    int config[7][7] = {
        {1, 1, 1, 1, 1, 1, -1}, // +
        {1, 1, 1, 1, 1, 1, -1}, // -
        {0, 0, 1, 1, 1, 1, -1}, // *
        {0, 0, 1, 1, 1, 1, -1}, // /
        {0, 0, 0, 0, 0, -1, -1}, // (
        {0, 0, 0, 0, 1, -1, -1} // )
    };
    return config[index1][index2];
}
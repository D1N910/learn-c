#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int data [10];
    int Lenght;
}Line;

void AddData(Line *, int);
void ExchangeData(int *, int *);

int main(void) {
    Line L;
    int x;
    _Bool iFhaveSame = false;

    L.Lenght = 0;

    scanf("%d", &x);
    while (x != -1)
    {
        scanf("%d", &x);
        AddData(&L, x);
    }

    // 利用冒泡查重
    for (int i = 0 ; i < L.Lenght;i++) {
        for (int j = L.Lenght -1; j > i;j--) {
            if (L.data[j] < L.data[j-1]) {
                ExchangeData(&L.data[j], &L.data[j-1]);
            } else if (L.data[j] == L.data[j-1]) {
                iFhaveSame = true;
                break;
            }
        }
    }

    if (iFhaveSame == true) {
        printf("true \n");
    } else {
        printf("false \n");
    }
}

// 添加数据
void AddData(Line *L, int x) {
    L->data[L->Lenght++] = x;
}

// 交换两个数据
void ExchangeData(int * x, int * y) {
    int mid = *x;
    *x = *y;
    *y = mid;
}
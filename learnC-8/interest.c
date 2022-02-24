#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    float enter_rateList[5];
    int enter_years;
    int enter_rateListLenth = (int) (sizeof(enter_rateList)/sizeof(enter_rateList[0]));
    printf("Enter interest rate:");
    scanf("%f", &enter_rateList[0]);
    printf("Enter number of years:");
    scanf("%d", &enter_years);

    float enter_yearsList[enter_years];

    // 填充年份钱
    for (int i = 0; i <= enter_years - 1;i++) {
        enter_yearsList[i] = 100;
    }
    
    // 打印表头
    printf("Years\t%3.0f%%   ", enter_rateList[0]);
    // 得到四个更高的利率，并打印
    for (int i = 1; i <= enter_rateListLenth - 1;i++) {
        enter_rateList[i] = enter_rateList[i - 1] + 1;
        printf("\t%3.0f%%   ", enter_rateList[i]);
    }
    // 换行
    printf("\n");
    
    // 打印每年的钱
    for (int i = 1; i <= enter_years; i++) {
        printf("%3d   ", i);
        for (int i = 0; i <= enter_rateListLenth - 1;i++) {
            enter_yearsList[i] = enter_yearsList[i] + enter_yearsList[i] * enter_rateList[i] / 100;
            printf("\t%7.02f", enter_yearsList[i]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
#include <stdio.h>

int main(void)
{
    float value_of_trade, trade_commission;
    printf("Enter value of trade:");
    scanf("%f", &value_of_trade);

    if (value_of_trade < 2500) {
        trade_commission = 30 + value_of_trade * 1.7f/100;
    } else if (value_of_trade < 6250){
        trade_commission = 56 + value_of_trade * 0.66f/100;
    } else if (value_of_trade < 20000){
        trade_commission = 76 + value_of_trade * 0.34f/100;
    } else if (value_of_trade < 50000){
        trade_commission = 100 + value_of_trade * 0.22f/100;
    } else if (value_of_trade < 500000){
        trade_commission = 155 + value_of_trade * 0.11f/100;
    } else {
        trade_commission = 255 + value_of_trade * 0.09f/100;
    }

    printf("Commission: $%.2f \n", trade_commission);
}
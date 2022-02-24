#include <stdio.h>

int main(void)
{
    float number_of_shares, price_per_share, value_of_trade, trade_commission_m, trade_commission_o;
    printf("Enter number of shares:");
    scanf("%f", &number_of_shares);
    printf("Enter price per share:");
    scanf("%f", &price_per_share);

    value_of_trade = number_of_shares * price_per_share;


    // 经纪人佣金
    if (value_of_trade < 2500) {
        trade_commission_m = 30 + value_of_trade * 1.7f/100;
    } else if (value_of_trade < 6250){
        trade_commission_m = 56 + value_of_trade * 0.66f/100;
    } else if (value_of_trade < 20000){
        trade_commission_m = 76 + value_of_trade * 0.34f/100;
    } else if (value_of_trade < 50000){
        trade_commission_m = 100 + value_of_trade * 0.22f/100;
    } else if (value_of_trade < 500000){
        trade_commission_m = 155 + value_of_trade * 0.11f/100;
    } else {
        trade_commission_m = 255 + value_of_trade * 0.09f/100;
    }

    // 竞争对手佣金
    if (number_of_shares < 2000) {
        trade_commission_o = number_of_shares * (33 + 3/100);
    } else {
        trade_commission_o = number_of_shares * (33 + 2/100);
    }


    printf("Commission: $%.2f \n", trade_commission_m);
    printf("Competitor's commission: $%.2f \n", trade_commission_o);
}
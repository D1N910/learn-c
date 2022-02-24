/* Write a program that format the product information entered by the user.
 */
#include <stdio.h>

int main(void)
{
    int item_number, purchase_date_yyyy, purchase_date_mm, purchase_date_dd;
    float unit_price;
    printf("Enter item number:");
    scanf("%d", &item_number);
    printf("Enter unit price:");
    scanf("%f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d / %d / %d", &purchase_date_mm, &purchase_date_dd, &purchase_date_yyyy);

    printf("Item\tUnit Price\tPurchase\n%d\t$%8.2f\t%d/%d/%d\n", item_number, unit_price, purchase_date_mm, purchase_date_dd, purchase_date_yyyy);

    return 0;
}
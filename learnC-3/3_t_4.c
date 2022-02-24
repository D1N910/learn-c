/* The books use Internal standard book number(ISBN) to sign.After 01/01/2007,
 * the descirpe ISBN include 13 numbers(the old ISBN use 10 numbers), devide
 * with five ground, i.g. 078-0-039-97950-3.
 * The first ground (GSI prefix) persent is 978 or 979.
 * The second ground (Ground sign) show language or initial country(i.g. 0 and 1 use
 * in country that speak English).
 * The third ground (Product number) that despire by chubanshan use to identify the book.
 * The last number of ISBN is a verify number, that uses to verify the currently of before number.
 * Write a number to divide user enter ISBN number.
 * 
 * Books are identified with an International Standard Book Number (ISBN).
 * ISBNs assigned after January 1, 2007 contain 10 digits (older ISBNs used 10 digilts)
 * and are divided into five groups, such as 978-0-393-9795-3.The first group (GSI prefix)
 * is currently 978 or 979.The second group (group identification) specifies the language of
 * country of original publication (e.g., 0 and 1 for English-speaking countries).The third ground
 * (publisher number) indicates the publisher (393 is the number of W.W Nortion Press).The fourth
 * group (product number) is assigned by the publisher to identify the specific book (97950).
 * A check digit at the end of the ISBN is used to verify the accuracy of the preceding number.
 * Write a program to break down the ISBN information entered by the user.
 */
#include <stdio.h>

int main(void)
{
    int gsi_prefix, group_identifier, publisher_code, item_number, check_digit;
    printf("Enter ISBN:");
    scanf("%d - %d - %d - %d - %d", &gsi_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);
    printf("GSI prefix: %d\n", gsi_prefix);
    printf("Group identifier: %d\n", group_identifier);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_number);
    printf("Check Digit: %d\n", check_digit);

    return 0;
}
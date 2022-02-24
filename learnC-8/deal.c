#include <stdbool.h> /*  C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 12

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int cards_number;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9',
                              't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand:");
    scanf("%d", &cards_number);


    printf("Your hand:");
    for (int i = 1;i <= cards_number;) {
        int rank_code_index = rand() % NUM_RANKS;
        int suit_code_index = rand() % NUM_SUITS;
        if (!in_hand[suit_code_index][rank_code_index]) {
            in_hand[suit_code_index][rank_code_index] = true;
            printf(" %c%c", rank_code[rank_code_index], suit_code[suit_code_index]);
            i++;
        }
    }
    printf("\n");
    return 0;
}
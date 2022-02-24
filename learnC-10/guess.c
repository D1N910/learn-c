/*
 * @Author: your name
 * @Date: 2022-02-20 20:42:13
 * @LastEditTime: 2022-02-20 21:09:25
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /learnC-10/guess.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int new_nums;
int guesses_num;

void play_game(void);
void initialize_number_generator(void);
void get_round(void);
void check_data(void);
void get_guesses_num(void);
void check_if_play_again(void);
void get_rand(void);

int main(void)
{
    printf("Guess the secret number between 1 and 100.");

    play_game();

    return 0;
}

void play_game(void)
{
    initialize_number_generator();

    get_rand();

    check_data();

    get_guesses_num();

    check_if_play_again();
}

/**
 * @brief 初始化C程序随机
 * 
 */
void initialize_number_generator(void)
{
    srand((unsigned) time(NULL));
}

/**
 * @brief 生成随机数
 * 
 */
void get_rand(void)
{
   new_nums = rand() % MAX_NUMBER + 1;
   guesses_num = 0;

   printf("\nA new numbers has been chosen. \n");
}

/**
 * @brief 
 * 
 */
void check_data(void)
{
    guesses_num++;
    int guesses;
    printf("Enter guess: ");
    scanf("%d", &guesses);
    if (guesses == new_nums) {
        return;
    }
    if (guesses > new_nums) {
        printf("Too high; try again.");
    } else if (guesses < new_nums){
        printf("Too low; try again.");
    }
    check_data();
}

/**
 * @brief 
 * 
 */
void get_guesses_num(void)
{
    printf("You won in %d guesses!\n\n", guesses_num);
}

/**
 * @brief 
 * 
 */
void check_if_play_again(void)
{
    char if_play;
    printf("Play again?(Y/N)");
    scanf(" %c", &if_play);
    if (if_play == 'Y' || if_play == 'y'){
        play_game();
    } else {
        exit(0);
    }
}
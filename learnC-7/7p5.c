#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int srabbleValue = 0;
    char ch;
    printf("Enter a word: ");
    while ((ch = getchar()) != '\n')
    {
        ch = toupper(ch);
        switch (ch)
        {
        case 'A':case 'E':case 'I':case 'L':case 'N':case 'O':case 'R':case 'S':case 'T':case 'U':
            srabbleValue += 1;
            break;
        case 'D':case 'G':
            srabbleValue += 2;
            break;
        case 'B':case 'C':case 'M':case 'P':
            srabbleValue += 3;
            break;
        case 'F':case 'H':case 'V':case 'W':case 'Y':
            srabbleValue += 4;
            break;
        case 'K':
            srabbleValue += 5;
            break;
        case 'J':case 'X':
            srabbleValue += 8;
            break;
        case 'Q':case 'Z':
            srabbleValue += 10;
            break;
        default:
            break;
        }
    }
    
    printf("Srabble value: %d\n", srabbleValue);
    return 0;
}
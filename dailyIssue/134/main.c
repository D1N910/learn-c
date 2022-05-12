#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char str[]="abcabcbb";
    // 存储最长无重复子串的起始和结束位置
    int lStartIndex=0;
    int lendIndex=0; // 

    // 存储临时无重复子串的起始和结束位置
    int startIndex=0; // 临时无重复子串的起始
    int endIndex=0; // 临时无重复子串的结束
    int temporaryStrL; // 临时无重复子串长度

    int strLength=sizeof(str)-1;

    // 空字符串和一个不处理
    if (strLength<=1) {
        printf("%s", str);
        return 0;
    }

    for (int i=1; i<=strLength-1; i++) {
        for (int j=startIndex;j<=endIndex;j++) {
            if (str[i] == str[j]) {
                temporaryStrL=endIndex-startIndex;
                if (temporaryStrL>lendIndex-lStartIndex) {
                    lendIndex=endIndex;
                    lStartIndex=startIndex;
                } // 同步
                startIndex = j+1;
                break;
            }
        }
        endIndex++;
        // 如果目前的开始和最长的开始不同，如果(字符串尾位置) - startIndex 小于 endIndex - startIndex，那么也没必要继续检索
        if (startIndex!=lStartIndex&&(strLength-startIndex)<(lStartIndex-lendIndex)) {
            break;
        }
    }

    temporaryStrL=endIndex-startIndex;
    if (temporaryStrL>lendIndex-lStartIndex) {
        lendIndex=endIndex;
        lStartIndex=startIndex;
    } // 同步

    printf("%ld\n", sizeof(str));
    printf("lStartIndex %d\n", lStartIndex);
    printf("lendIndex %d\n", lendIndex);

    for (int z=lStartIndex;z<=lendIndex;z++) {
        printf("%c", str[z]);
    }
    printf("\n");

    return 0;
}

/**
 * @brief 
 * 从第二个开始遍历
 *      从现在字符串头往后检索，如果检索到有重复的
 *          如果(endIndex - startIndex) > (lendIndex - lStartIndex)
 *              那么同步lendIndex=endIndex;lStartIndex=startIndex;
 *          startIndex+1，endIndex+1
 *          如果(字符串长度 - 1) - startIndex 小于 endIndex - startIndex
 *          那么打断遍历
 * 如果检索到没有重复的，那么startIndex不变，endIndex+1
 * 遍历完毕
 * 如果(endIndex - startIndex) > (lendIndex - lStartIndex)
 * 那么同步lendIndex=endIndex;lStartIndex=startIndex;
 */
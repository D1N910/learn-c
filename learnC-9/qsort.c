#include <stdio.h>
#define N 10

void quicksort(int [N], int, int);
int split_nums(int hight_index, int low_index, int nums[N]);

int main(void)
{
    int index = 0;
    int nums[N];
    printf("Please enter %d number to be sorts: ", N);

    // 读取数据
    while (index < N)
    {
        scanf("%d", &nums[index]);
        index++;
    }

    quicksort(nums, 0, N - 1);

    index = 0;
    printf("In sorted order: ");
    // 读取数据
    while (index < N)
    {
        printf("%d ", nums[index]);
        index++;
    }

    printf("\n");
    
    return 0;
}

/**
 * @brief 快速排序
 * 
 * @param nums 
 * @return int 
 */
void quicksort(int nums[N], int low_index, int hight_index)
{
    int split_number; // 存储用以分割的数
    if (low_index >= hight_index) return;

    int middle = split_nums(hight_index, low_index, nums);

    quicksort(nums, low_index, middle - 1);
    quicksort(nums, middle + 1, hight_index);
}

// 执行分割函数
int split_nums(int hight_index, int low_index, int nums[N])
{
    int split_number = nums[low_index];
    
    for (;;) {
        while (low_index < hight_index && split_number <= nums[hight_index])
            hight_index--;
        if (low_index >= hight_index) break;
        nums[low_index++] = nums[hight_index];

        while (low_index < hight_index &&  nums[low_index] <= split_number)
            low_index++;
        if (low_index >= hight_index) break;
        nums[hight_index--] = nums[low_index];
    }

    nums[hight_index] = split_number;
    return hight_index; // 分割的位置
}
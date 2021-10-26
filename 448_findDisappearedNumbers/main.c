#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
    // 使用交换
    // 两个循环
    int temp;
    for (int i = 0; i < numsSize; i++) {
        while (i + 1 != nums[i]) {
            if (nums[nums[i] - 1] != nums[i]) {
                temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            } else {
                break;
            }
        }
    }
    int* result = malloc(sizeof(int) * (numsSize / 2));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i + 1 != nums[i]) {
            result[*returnSize] = i + 1;
            *returnSize = *returnSize + 1;
        }
    }
    return result;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int *returnSize = malloc(sizeof(int));
    findDisappearedNumbers(nums, 8, returnSize);
    return 0;
}

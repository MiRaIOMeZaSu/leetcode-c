#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    // 穷举法寻找数组中加和为指定值得两个数
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int *ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


int main() {
    int nums[] = {0};
    int *returnSize = malloc(sizeof(int));
    *returnSize = 1;
    twoSum(nums, 1, 1, returnSize);
    printf("Hello, World!\n");
    return 0;
}

#include <stdio.h>

int maxSubArray(int *nums, int numsSize) {
    // 使用双指针?
    // 使用动态规划
    int dp[numsSize];
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
    }
    int sum = dp[0];
    for (int i = 1; i < numsSize; i++) {
        if (dp[i] > sum) {
            sum = dp[i];
        }
    }
    return sum;
}

int main() {
    int nums[] = {-1};
    int sum = maxSubArray(nums, 1);
    printf("%d", sum);
    return 0;
}

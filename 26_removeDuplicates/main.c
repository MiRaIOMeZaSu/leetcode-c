#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    // 数组有序
    // 返回最终的数组长度
    // 双指针
    if(numsSize<2){
        return numsSize;
    }
    int slow = 0;
    int fast = 1;
    while (fast < numsSize) {
        while (fast < numsSize && nums[slow] == nums[fast]) {
            fast++;
        }
        slow++;
        if (fast < numsSize&&slow<numsSize) {
            nums[slow] = nums[fast];
        }
    }
    return slow;
}

int main() {
    int num[] = {1, 1, 2};
    printf("%d\n", removeDuplicates(num, 3));
    return 0;
}

#include <stdio.h>

// 使用位运算
int singleNumber(int* nums, int numsSize){
    int sum = 0;
    for(int i = 0;i<numsSize;i++){
        sum ^= nums[i];
    }
    return sum;
}

int main() {
    int nums[] = {1,2,2};
    int ret = singleNumber(nums,3);
    return 0;
}

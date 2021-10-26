#include <stdio.h>

// 使用分治法 - 需要的是最小的数字
int divideAndConquer(int *nums, int numsSize, int *ret, int k) {
    switch (numsSize) {
        case 2:
            if (nums[1] > nums[0]) {
                ret[0] = nums[0];
                ret[1] = nums[1];
                return 2;
            } else {
                ret[1] = nums[0];
                ret[0] = nums[1];
                return 2;
            }
        case 1:
            ret[0] = nums[0];
            return 1;
    }
    if (numsSize > 2) {
        // numsSize > 2
        int mid = numsSize / 2;
        int retL[k];
        int retR[k];
        int leftSize = divideAndConquer(nums, mid, retL, k);
        int rightSize = divideAndConquer(nums + mid, numsSize - mid, retR, k);
        int i = 0;
        int l = 0;
        int r = 0;
        while (i < k && l < leftSize && r < rightSize) {
            if (retL[l] < retR[r]) {
                ret[i] = retL[l];
                l++;
                i++;
            } else {
                ret[i] = retR[r];
                r++;
                i++;
            }
        }
        if (i == k) {
            return k;
        } else {
            if (l == leftSize) {
                while (i < k && r < rightSize) {
                    ret[i] = retR[r];
                    i++;
                    r++;
                }
            } else {
                while (i < k && l < leftSize) {
                    ret[i] = retL[l];
                    i++;
                    l++;
                }
            }
            return i;
        }

    }
}

int main() {
    int size, k;
    scanf("%d", &size);
    scanf("%d", &k);
    k++;
    int nums[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
    int ret[k];
    int returnSize = divideAndConquer(nums, size, ret, k);
    for (int i = 0; i < returnSize; i++) {
        if (i == k - 1) {
            printf("%d ", ret[i]);
        }
    }
    return 0;
}

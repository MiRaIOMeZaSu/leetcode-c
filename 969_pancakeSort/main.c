#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void solve(int *arr, int arrSize, int *returnSize, int *result) {
    if (arrSize == 2) {
        if (arr[0] <= arr[1]) {
            return;
        } else {
            result[*returnSize] = 2;
            *returnSize = *returnSize + 1;
            return;
        }
    }
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    if (maxIndex == arrSize - 1) {
        solve(arr, arrSize - 1, returnSize, result);
        return;
    }
    if (maxIndex != 0) {
        // 翻转
        result[*returnSize] = maxIndex + 1;
        *returnSize = *returnSize + 1;
    }
    int right = maxIndex;
    int left = 0;
    int temp;
    while (right > left) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        right--;
        left++;
    }
    *arr++;
    left = 0;
    right = arrSize - 1 - 1;
    while (right > left) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        right--;
        left++;
    }
    result[*returnSize] = arrSize;
    *returnSize = *returnSize + 1;
    solve(arr, arrSize - 1, returnSize, result);
}

int *pancakeSort(int *arr, int arrSize, int *returnSize) {
    int *ret = malloc(sizeof(int) * arrSize * 10);
    *returnSize = 0;
    if (arrSize <= 1) {
        return ret;
    }
    solve(arr, arrSize, returnSize, ret);
    return ret;
}

int main() {
    int arr[] = {2, 3, 1};
    int *returnSize = malloc(sizeof(int));
    int *result = pancakeSort(arr, 3, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}

#include <stdio.h>

// 使用冒泡排序
// 划分的是分数线
void swap(int *nums, int a, int b) {
    int temp0 = *(nums + a * 2);
    int temp1 = *(nums + a * 2 + 1);
    *(nums + a * 2) = *(nums + b * 2);
    *(nums + a * 2 + 1) = *(nums + b * 2 + 1);
    *(nums + b * 2) = temp0;
    *(nums + b * 2 + 1) = temp1;
}

int main() {
    int size;
    int m;
    scanf("%d", &size);
    scanf("%d", &m);
    int targetSize = m * 1.5;
    int count = 0;
    int nums[size][2];
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i][0]);
        scanf("%d", &nums[i][1]);
    }
    int index;
    // 找到分数线后停止
    while (count < targetSize && count < size) {
        index = 0;
        int num = nums[index][1];
        for (int n = 0; n < size - count; n++) {
            if (num < nums[n][1]) {
                num = nums[n][1];
                index = n;
            } else if (num == nums[n][1]) {
                if (nums[index][0] > nums[n][0]) {
                    num = nums[n][1];
                    index = n;
                }
            }
        }
        if (size - count - 1 != index) {
            swap(nums, index, size - count - 1);
        }
        count++;
    }

    // 此时count = targetSize
    int targetScore = nums[size - count][1];
    while (count < size) {
        index = 0;
        int num = nums[index][1];
        for (int n = 0; n < size - count; n++) {
            if (num < nums[n][1]) {
                num = nums[n][1];
                index = n;
            } else if (num == nums[n][1]) {
                if (nums[index][0] > nums[n][0]) {
                    num = nums[n][1];
                    index = n;
                }
            }
        }
        if (size - count - 1 != index) {
            swap(nums, index, size - count - 1);
        }
        if (nums[size - count - 1][1] < targetScore) {
            break;
        }
        count++;
    }
    printf("%d %d\n", targetScore, count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", nums[size - 1 - i][0], nums[size - 1 - i][1]);
    }
    // 后续继续进行排序直到新数字小于分数线
    return 0;
}

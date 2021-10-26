#include <stdio.h>
#include <string.h>

int main() {
    int size, amount;
    scanf("%d%d", &size, &amount);
    int *nums[size];
    memset(nums, 0, sizeof(nums));
    int input;
    for (int i = 0; i < amount; i++) {
        scanf("%d", &input);
        nums[input - 1] += 1;
    }
    int i;
    for (i = 1; i <= size; i++) {
        if (nums[i - 1] != 0) {
            printf("%d", i);
            nums[i - 1] -= 1;
            break;
        }
    }
    for (; i <= size; i++) {
        while (nums[i - 1] != 0) {
            printf(" %d", i);
            nums[i - 1] -= 1;
        }
    }
    return 0;
}

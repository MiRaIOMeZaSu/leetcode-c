#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n != (n & (n - 1))) {
        n = n & (n - 1);
        result++;
    }
    return result;
}

int main() {
    printf("%d",hammingWeight(00000000000000000000000000001011));
    return 0;
}

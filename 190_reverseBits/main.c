#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 31; i++) {
        if (n % 2 != 0) {
            ret++;
        }
        ret *= 2;
        n /= 2;
    }
    if (n == 1) {
        ret++;
    }
    return ret;
}

int main() {
    printf("Hello, World!\n");
    uint32_t a = 4294967293;
    uint32_t ret = reverseBits(a);
    printf(ret);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if(n<1){
        return false;
    }
    if (!(n & (n - 1))) {
        // 只存在一个1
        return true;
    }
    return false;
}

int main() {
    isPowerOfTwo(16);
    return 0;
}

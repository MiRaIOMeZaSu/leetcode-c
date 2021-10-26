#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int calculate(char *s) {
    int size = strlen(s);
    int result = 0;
    int num = 0;
    int solution = 1;
    char lastOperator = '+';

    int i = 0;
    while (i < size) {
        if (s[i] == ' ') {
        } else if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if ((i + 1 < size && !isdigit(s[i + 1])) || i + 1 >= size) {
                // 此时可以开始计算
                switch (lastOperator) {
                    case '+':
                        solution = num;
                        break;
                    case '-':
                        solution = -num;
                        break;
                    case '*':
                        solution = solution * num;
                        break;
                    case '/':
                        solution = solution / num;
                        break;
                        // 下一个是数字
                }
                num = 0;
            }
        } else {
            lastOperator = s[i];
            if (lastOperator == '+' || lastOperator == '-') {
                result += solution;
            }
        }
        i++;
    }
    return result + solution;
}

int main() {
    char s[] = "32+2*2";
    printf("%d", calculate(s));
    return 0;
}

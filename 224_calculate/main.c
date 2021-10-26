#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int solve(char *s, int *i) {
    int size = strlen(s);
    int result = 0;
    int num = 0;
    int solution = 0;
    char lastOperator = '+';

    while (i[0] < size) {
        if (s[i[0]] == ' ') {
        } else if (s[i[0]] == '(') {
            i[0]++;
            switch (lastOperator) {
                case '+':
                    result += solve(s, i);
                    break;
                case '-':
                    result -= solve(s, i);
                    break;
                    // 下一个是数字
            }
            solution = 0;
        } else if (s[i[0]] == ')') {
            return result + solution;
        } else if (isdigit(s[i[0]])) {
            num = num * 10 + (s[i[0]] - '0');
            if ((i[0] + 1 < size && !isdigit(s[i[0] + 1])) || i[0] + 1 >= size) {
                // 此时可以开始计算
                switch (lastOperator) {
                    case '+':
                        solution = num;
                        break;
                    case '-':
                        solution = -num;
                        break;
                        // 下一个是数字
                }
                num = 0;
            }
        } else {
            lastOperator = s[i[0]];
            result += solution;
        }
        i[0]++;
    }
    return result + solution;
}

int calculate(char *s) {
    int n[1] = {0};
    int *i = n;
    return solve(s, i);
}

int main() {
    char s[] = "(1+(4+5+2)-3)+(6+8)";
    printf("%d", calculate(s));
    return 0;
}

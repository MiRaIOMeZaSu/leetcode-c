#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
// 使用基数排序(使用队列)
// 先按桶排序根据位数
// 再从前往后排
 */

//实际上只需要比较大小


int main() {
    int size;
    scanf("%d", &size);
    char *pre = (char *) malloc(sizeof(char) * (1000 + 1));;
    char *buff = (char *) malloc(sizeof(char) * (1000 + 1));
    gets(buff);
    gets(buff);
    int preSize = strlen(buff);
    strcpy(pre, buff);
    int i = 1;
    int index = 1;
    for (; i < size; i++) {
        gets(buff);
        int strLen = strlen(buff);
        if (strLen > preSize) {
            strcpy(pre, buff);
            index = i + 1;
            preSize=strLen;
        } else if (strLen == preSize) {
            for (int s = 0; s < strLen; s++) {
                if (buff[s] > pre[s]) {
                    strcpy(pre, buff);
                    index = i + 1;
                    preSize=strLen;
                } else if (buff[s] < pre[s]) {
                    break;
                }
            }
        }
    }
    printf("%d\n", index);
    for (int y = 0; y < preSize; y++) {
        printf("%c", pre[y]);
    }
    printf("\n");
    return 0;
}

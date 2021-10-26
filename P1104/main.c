#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int year;
    int month;
    int day;
    char name[100];
};

int main() {
    int size;
    scanf("%d", &size);
    struct Student student[size];
    char buff[100];
    char *token;
    gets(buff);
    for (int i = 0; i < size; i++) {
        gets(buff);
        token = strtok(buff, " ");
        strcpy(student[i].name, token);
        token = strtok(NULL, buff);
        student[i].year = atoi(token);
        token = strtok(NULL, buff);
        student[i].month = atoi(token);
        token = strtok(NULL, buff);
        student[i].day = atoi(token);
    }
    for (int i = 0; i < size; i++) {
        printf(student[i].name);
    }
    return 0;
}

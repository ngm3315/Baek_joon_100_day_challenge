/*https://blog.naver.com/ngm3315/224008092535*/
#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int q[10000];
int head = 0, tail = 0;

void push(int x) { q[tail++] = x; }
void pop(void) {
    if (head == tail) printf("-1");
    else printf("%d\n", q[head++]);
}
void size() { printf("%d\n", tail - head); }
void empty() { printf("%d\n", head == tail ? 1 : 0); }
void front() {
    if (head == tail) puts("-1");
    else printf("%d\n", q[head]);
}
void back() {
    if (head == tail) puts("-1");
    else printf("%d\n", q[tail - 1]);
}

int main(void) {
    int n;
    scanf("%d", &n);
    char cmd[16];

    for (int i = 0; i < n; i++) {
        scanf("%15s", cmd);
        if (!strcmp(cmd, "push")) {
            int x; scanf("%d", &x);
            push(x);
        }
        else if (!strcmp(cmd, "pop")) {
            pop();
        }
        else if (!strcmp(cmd, "size")) {
            size();
        }
        else if (!strcmp(cmd, "empty")) {
            empty();
        }
        else if (!strcmp(cmd, "front")) {
            front();
        }
        else if (!strcmp(cmd, "back")) {
            back();
        }
    }
    return 0;
}

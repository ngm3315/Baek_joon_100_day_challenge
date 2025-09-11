/*https://blog.naver.com/ngm3315/224004448386*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int n, char** input) {
    for (int i = 0; i < n; i++) {
        int len = (int)strlen(input[i]);

        if (len % 2 != 0 || input[i][0] != '(' || input[i][len - 1] != ')') {
            puts("NO");
            continue;
        }

        int bal = 0, ok = 1;
        for (int j = 0; j < len; j++) {
            if (input[i][j] == '(') bal++;
            else if (input[i][j] == ')') {
                if (--bal < 0) { ok = 0; break; }
            }
        }
        if (bal != 0) ok = 0;

        puts(ok ? "YES" : "NO");
    }
    return 0;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    char** input = (char**)malloc(sizeof(char*) * n);
    if (!input) return 0;

    for (int i = 0; i < n; i++) {
        input[i] = (char*)malloc(101);
        scanf("%s", input[i]);
    }

    check(n, input);

    for (int i = 0; i < n; i++) free(input[i]);
    free(input);
    return 0;
}

/*https://blog.naver.com/ngm3315/224009785526*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char** input) {
    int len[2];
    for (int i = 0; i < 2; i++) {
        len[i] = strlen(input[i]);
    }

    // dp[i][j] = input[0][0..i-1], input[1][0..j-1]까지의 LCS 길이
    int** dp = malloc(sizeof(int*) * (len[0] + 1));
    for (int i = 0; i <= len[0]; i++) {
        dp[i] = calloc(len[1] + 1, sizeof(int)); // calloc으로 0 초기화
    }

    for (int i = 1; i <= len[0]; i++) {
        for (int j = 1; j <= len[1]; j++) {
            if (input[0][i - 1] == input[1][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ?
                    dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // 결과 출력
    printf("%d\n", dp[len[0]][len[1]]);

    // 메모리 해제
    for (int i = 0; i <= len[0]; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main(void) {
    char** input = malloc(sizeof(char*) * 2);
    for (int i = 0; i < 2; i++) {
        input[i] = malloc(sizeof(char) * 1001); // 최대 1000 + 널문자
        scanf("%s", input[i]);
    }

    check(input);

    // 메모리 해제
    for (int i = 0; i < 2; i++) {
        free(input[i]);
    }
    free(input);

    return 0;
}


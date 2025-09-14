/*https://blog.naver.com/ngm3315/224007997126*/
#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 



int main(void){

    int n;
    scanf("%d",&n);
    char**input=malloc(sizeof(char*)*n);
    for(int i =0; i<n;i++){
        input[i] = malloc(sizeof(char)*101);
        scanf("%s",input[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(input[j]) > strlen(input[j + 1]) ||
               (strlen(input[j]) == strlen(input[j + 1]) &&
                strcmp(input[j], input[j + 1]) > 0)){
                char* temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%s\n", input[i]);
    }
    for (int i = 0; i < n; i++) {
        free(input[i]);
    }
    free(input);
}

/*https://blog.naver.com/ngm3315/224006586869*/
#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int n,m;

int main(void){
    srand(time(NULL)); 
    scanf("%d",&n);
 

    int *random = malloc(sizeof(int)*n);
    int *random2 = malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) { // 10번 반복
		random[i] = rand()%n+1; // 난수 생성
		printf("%d ", random[i]);
        // 출력
    }
    printf("\n");
    scanf("%d",&m);
    for (int i = 0; i < m; i++) { // 10번 반복
		random2[i] = rand()%n+1; // 난수 생성
		printf("%d ", random2[i]);
        // 출력
    }
    printf("\n");
    
    int *count=malloc(sizeof(int)*m);
    for (int i = 0; i < m; i++) { // 10번 반복
		count[i] =0;
    }



    for (int i = 0; i < m; i++) { // 10번 반복
		

        for(int k = 0 ; k < n;k++){
            if (random2[i]==random[k]){
                count[i]++;
                continue;
            }
            else continue;
        }
        if(count[i]>0){
            printf("1");
        }
        else printf("0");

        printf("\n");

    }





   free(random);
   free(random2);
   free(count);
    return 0;
}

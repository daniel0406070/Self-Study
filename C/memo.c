#include <stdio.h>
<<<<<<< HEAD

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }

        for(int j = 2*n-2*i-1; j >0 ; j--){
            printf("*");
        }
        printf("\n");
    }
=======
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    int a_len=strlen((char *)a);
    int b_len=strlen((char *)b);
    
    while(a_len>0&&b_len>0){
        if(*(char *)a>*(char *)b){
            return 1;
        }
        else if(*(char *)a<*(char *)b){
            return -1;
        }
        a++;
        b++;
        a_len--;
        b_len--;
    }

     return a_len-b_len;
}

int main(){
    char str[5][100];
    for(int i=0; i<5; i++){
        fgets(str[i], sizeof(str[i]), stdin);
    }

    qsort(str, 5, sizeof(str[0]), cmp);

    for(int i=0; i<5; i++){
        printf("%s", str[i]);
    }
    
>>>>>>> origin/master
}
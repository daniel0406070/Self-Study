#include <stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    if(a+d > b+c){
        printf("Persepolis\n");
    }else if(a+d < b+c){
        printf("Esteghlal\n");
    }else{
        if(d > b){
            printf("Persepolis\n");
        }else if(d < b){
            printf("Esteghlal\n");
        }else{
            printf("Penalty\n");
        }
    }
}
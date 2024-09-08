#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if(a>=1000){
        if(b>=8000 || c>=260) printf("Very Good");
        else printf("Good");
    }
    else{
        printf("Bad");
    }
}
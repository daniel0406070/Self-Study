#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    if(n < 2) printf("Before");
    else if(n > 2) printf("After");
    else{
        if(m < 18) printf("Before");
        else if(m > 18) printf("After");
        else printf("Special");
    }
}
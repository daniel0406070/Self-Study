#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    int sum = 0;
    int min = 0;

    for(int i = 1; i*i<= m; i++){
        int isqrt = i * i;
        if(isqrt >= n && isqrt <= m){
            sum += isqrt;
            if(min == 0) min = isqrt;
        }
    }

    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}
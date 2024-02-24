#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a,b,min=0x7fffffff;
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        if(b<a) continue;
        min = min > b ? b : min;
    }
    
    if(min == 0x7fffffff) printf("-1");
    else printf("%d", min);
}
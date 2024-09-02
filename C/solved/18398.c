#include <stdio.h>

int main(){
    int n,k,a,b;
    scanf("%d", &k);

    for(int i = 0; i < k; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a+b, a*b);
        }
    }
}

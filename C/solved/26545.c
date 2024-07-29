#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        sum += tmp;
    }
    printf("%d\n", sum);
}
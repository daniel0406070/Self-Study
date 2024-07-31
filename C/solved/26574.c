#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        printf("%d %d\n", tmp, tmp);
    }
}
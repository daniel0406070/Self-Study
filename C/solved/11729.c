#include <stdio.h>

void hanoi(int n, int from, int to, int by){
    if(n==1){
        printf("%d %d\n", from, to);
    }else{
        hanoi(n-1, from, by, to);
        printf("%d %d\n", from, to);
        hanoi(n-1, by, to, from);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", (1<<n)-1);
    hanoi(n, 1, 3, 2);
}
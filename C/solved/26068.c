#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int a[1003];
    for(int i=0; i<n; i++){
        scanf("\nD-%d", &a[i]);
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]<=90){
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    int xor = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        xor ^= arr[i];
    }

    for(int i = 0; i < n; i++){
        ans = (xor ^ arr[i]) > ans ? (xor ^ arr[i]) : ans;
    }
    ans = xor > ans ? xor : ans;

    printf("%d%d\n", ans, ans);
}
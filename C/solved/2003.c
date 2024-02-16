#include <stdio.h>

int main(){
    int n,m,sum = 0, cnt = 0;
    int num[10002];
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    int i = 0, j = 0;
    while(j <= n){
        if(sum < m){
            sum += num[j++];
        }else if(sum == m){
            cnt++;
            sum += num[j++];
        }else{
            sum -= num[i++];
        }
    }

    printf("%d", cnt);
}
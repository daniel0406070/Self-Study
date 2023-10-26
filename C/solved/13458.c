#include <stdio.h>


int p[1000002];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    int b, c;
    scanf("%d %d", &b, &c);

    long long ans = 0;
    for(int i = 0; i < n; i++){
        p[i] -= b;
        ans++;
        if(p[i] > 0){
            ans += p[i] / c;
            if(p[i] % c != 0){
                ans++;
            }
        }
    }

    printf("%lld\n", ans);
}
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n;
    int m;
    int arr[100];

    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d", &arr[i]);
        }

        long long sum = 0;
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        printf("%lld\n", sum);
    }
}
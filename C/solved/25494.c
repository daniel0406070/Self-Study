#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        int cnt = 0;

        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                for(int k = 1; k <= c; k++){
                    if(i%j == j%k && j%k == k%i){
                        cnt++;
                    }
                }
            }
        }

        printf("%d\n", cnt);
    }
}
#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a,b,i;
        short int f[6];
        scanf("%d %d", &a, &b);

        f[0] = (a-1)%10+1;
        for(i=1; i<6; i++){
            f[i] = (f[i-1]*a-1)%10+1;
            if (f[i] == f[0]) {
                break;
            }
        }

        // printf("%d\n", i);
        printf("%d\n", f[(b-1)%i]);
    }
}
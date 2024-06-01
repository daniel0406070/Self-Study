#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b=0, c=0;
        scanf("%d", &a);
        for(int j=0; j<a; j++){
            int d;
            double e;
            scanf("%d %lf", &d, &e);
            b += d;
            c += d * e * 10;
        }
        printf("%d %.1f\n", b, (float)c/b/10);
    }
}
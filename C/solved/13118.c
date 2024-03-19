#include <stdio.h>
#include <math.h>

int main(){
    int a[4];
    for(int i = 0; i < 4; i++){
        scanf("%d", &a[i]);
    }

    int x,y,r;
    scanf("%d %d %d", &x, &y, &r);

    for(int i = 0; i < 4; i++){
        if(a[i] == x){
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("0\n");
}
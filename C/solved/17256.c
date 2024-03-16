#include <stdio.h>

int main(){
    int a[6];
    for(int i=0; i<6; i++){
        scanf("%d", &a[i]);
    }
    printf("%d %d %d", a[3]-a[2], a[4]/a[1], a[5]-a[0]);
    return 0;
}
#include <stdio.h>

int main(){
    int n;
    int rail[1000][2];
    int min=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &rail[i][0], &rail[i][1]);
        if(rail[min][1]>rail[i][1]) min=i;
    }

    printf("%d %d\n", rail[min][0], rail[min][1]);
}
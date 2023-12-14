#include <stdio.h>

int main(){
    int a[4], b[2];
    for(int i = 0; i < 4; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 2; i++) scanf("%d", &b[i]);

    int sum = 0;
    int min = a[0];

    for(int i = 0; i < 4; i++){
        sum += a[i];
        if(a[i] < min) min = a[i];
    }
    sum -= min;

    if(b[0] > b[1]) sum += b[0];
    else sum += b[1];

    printf("%d", sum);
}
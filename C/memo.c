#include <stdio.h>
#include <math.h>

int main(){
    for(int i = 0; i < 700; i++){
        printf("%d %lf\n", i, 175*(1-pow(0.995, i)));
    }
}
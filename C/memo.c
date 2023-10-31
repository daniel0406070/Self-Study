#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    for(int i=300; i<3000; i++){
        printf("%d %d\n", i, (int)floor(175*(1-pow(0.995, i))+0.5));
    }
}
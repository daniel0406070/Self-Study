#include <stdio.h>



int main(){
    int a[][2]={{1,2},{3,4}};
    int *b=a[0];
    printf("a[0][0] = %d\n",b[3]);

}
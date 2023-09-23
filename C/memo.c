#include <stdio.h>


int main(){
    int n;
    n=20;

    printf("%d\n", n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", 0);
        }
        printf("\n");
    }
}
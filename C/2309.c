#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int ans = 0;
    int a[9];
    for (int i = 0; i < 9; ++i){
        scanf("%d", &a[i]);
        ans += a[i];
    }

    qsort(a, 9, sizeof(int), cmp);


    
    for (int i = 0; i < 9; ++i){
        for (int j = i+1; j < 9; ++j){
            if (ans - a[i] - a[j] == 100){
                for (int k = 0; k < 9; ++k){
                    if (k != i && k != j){
                        printf("%d\n", a[k]);
                    }
                }
                return 0;
            }
        }
    }
}
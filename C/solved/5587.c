#include <stdio.h>
#include <stdlib.h>

int a[102];
int va[102]={0};
int b[102];
int vb[102]={0};
int n;

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){    
    int aidx = 0;
    int bidx = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    a[n] = 2*n+1;

    if(a[0] != 1){
        for(int i = 1; i < a[0]; i++){
            b[bidx++] = i;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = a[i]+1; j < a[i+1]; j++){
            b[bidx++] = j;
        }
        
    }
    bidx = 0;

    int show = 0;
    int turn = 0;
    int i;
    while(aidx < n && bidx < n){
        if(turn == 0){
            for(i = 0; i < n; i++){
                if(va[i] == 0 && a[i] > show){
                    va[i] = 1;
                    show = a[i];
                    aidx++;
                    break;
                }
            }
            if(i==n){
                show = 0;
            }

            turn = 1;
        }
        else{
            for(i = 0; i < n; i++){
                if(vb[i] == 0 && b[i] > show){
                    vb[i] = 1;
                    show = b[i];
                    bidx++;
                    break;
                }
            }
            if(i==n){
                show = 0;
            }

            turn = 0;
        }
    }

    printf("%d\n", n-bidx);
    printf("%d\n", n-aidx);
}
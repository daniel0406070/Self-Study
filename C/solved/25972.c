#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int domino[500002][2];

int cmp(const void *a, const void *b){
    int *pa = (int *)a;
    int *pb = (int *)b;

    
    return pa[0] - pb[0];
}

int main(){
    int n;
    scanf("%d", &n);

    int a,l;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &l);
        domino[i][0] = a;
        domino[i][1] = l;
    }
    qsort(domino, n, sizeof(int)*2, cmp);

    int count = 0;
    for(int i = 0; i < n; i++){
        if (domino[i][0] == 0) continue;
        
        int a=domino[i][0];
        int l=domino[i][1];
        int j=i+1;
        while(j<n){
            if(a<domino[j][0]&&domino[j][0]<=a+l){
                a=domino[j][0];
                l=domino[j][1];
                domino[j][0] = 0;
                domino[j][1] = 0;
                j++;
            }
            else break;
        }
        count++;
    }

    printf("%d", count);

}
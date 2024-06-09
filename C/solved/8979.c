#include <stdio.h>
#include <stdlib.h>

int cmp(const void *b, const void *a){
    int *x = (int *)a;
    int *y = (int *)b;

    if(x[1] == y[1]){
        if(x[2] == y[2]){
            return x[3] - y[3];
        }
        return x[2] - y[2];
    }
    return x[1] - y[1];
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[1004][4];
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
    }

    qsort(arr, n, sizeof(arr[0]), cmp);

    int rank = 1;
    for(int i = 0; i < n; i++){
        if(arr[i][0] == k){
            for(int j = i-1; j >= 0; j--){
                if(arr[j][1] == arr[i][1] && arr[j][2] == arr[i][2] && arr[j][3] == arr[i][3]){
                    rank--;
                }
                else{
                    break;
                }
            }
            printf("%d\n", rank);
            break;
        }
        rank++;
    }

    return 0;

}
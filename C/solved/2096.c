#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int arr[3];
    int max_arr[3];
    int min_arr[3];
    int max_arr_next[3];
    int min_arr_next[3];

    scanf("%d", &n);

    for(int j=0; j<3; j++){
        scanf("%d", &arr[j]);

        max_arr[j] = arr[j];
        min_arr[j] = arr[j];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &arr[j]);
        }

        for(int j=0; j<3; j++){
            int max = 0;
            int min = 0x7fffffff;
            for(int k=-1; k<=1; k++){
                int prev_j = j+k;
                if(prev_j<0||prev_j>2) continue;
                if(max_arr[prev_j]>max){
                    max = max_arr[prev_j];
                }
                if(min_arr[prev_j]<min){
                    min = min_arr[prev_j];
                }
            }
            max_arr_next[j] = max + arr[j];
            min_arr_next[j] = min + arr[j];
        }
        for(int j=0; j<3; j++){
            max_arr[j] = max_arr_next[j];
            min_arr[j] = min_arr_next[j];
        }
    }

    int result_max = 0;
    int result_min = 0x7fffffff;
    for(int j=0; j<3; j++){
        if(max_arr[j]>result_max){
            result_max = max_arr[j];
        }
        if(min_arr[j]<result_min){
            result_min = min_arr[j];
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d ", max_arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d ", min_arr[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d %d\n", result_max, result_min);
}
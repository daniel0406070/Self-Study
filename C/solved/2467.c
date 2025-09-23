#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    long long int* nums = (long long int*)malloc(n * sizeof(long long int));
    for(int i = 0; i < n; i++){
        scanf("%lld", &nums[i]);
    }

    int idxs = 0, idxe = n - 1;

    long long int close_zero = labs(nums[idxs] + nums[idxe]);
    int close_s = idxs, close_e = idxe;

    while(idxs < idxe){
        long long int sum = nums[idxs] + nums[idxe];
        if(labs(sum) < close_zero){
            close_zero = labs(sum);
            close_s = idxs;
            close_e = idxe;
        }

        if(sum < 0){
            idxs++;
        } else if(sum > 0){
            idxe--;
        } else {
            break;
        }
    }

    printf("%lld %lld\n", nums[close_s], nums[close_e]);
}
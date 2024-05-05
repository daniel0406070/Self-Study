#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define test 0

int main(){
    long long int n, q, ball_num;
    
    scanf("%lld",&n);
    if(!test) scanf("%lld",&q);
    else{
        q=1;
        for(int i = 0; i<n; i++) q *= 2;
        q--;
    }

    

    char bit[64];
    for(long long int i = 0; i<q; i++){
        if(!test) scanf("%lld",&ball_num);
        else ball_num = i+1;

        long long int bit_tmp = ball_num-1;
        for(int j = 0; j<64; j++) bit[j] = 0;
        long long int bit_idx = 0;
        while(bit_tmp>0){
            bit[bit_idx++] = bit_tmp%2;
            bit_tmp /= 2;
        }


        long long int empty_num = 1;
        for(int j = 0; j<n; j++) empty_num *= 2;
        empty_num-=ball_num;

        long long int depth = 0;
        while(empty_num>0){
            depth++;
            empty_num /= 2;
        }
        depth--;

        long long int ans = 1;
        int dir = 0;
        for(long long int j = 0; j<depth; j++){
            if(bit[j] == 1) dir = !dir;
            
            if(dir == 1) ans *= 2;
            else ans = ans*2+1;
            
        }
        printf("%lld\n",ans);
        // printf("%lld: %lld\n", ball_num, ans);
    }
}
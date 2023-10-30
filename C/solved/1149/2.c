#include <stdio.h>
#include <stdlib.h>


long long int arr[1500000];
int idx=0;

void meas(long long int a){
    for(long long int i=1; i*i<=a; i++){
        if(a%i==0){
            arr[idx++]=i;
        }
    }
}


int main(){
    long long int a,b,k;
    scanf("%lld %lld %lld", &a, &b, &k);
    
    meas(a+b);

    if (a<=k||b<=k) {
        printf("%lld\n", a+b);
        return 0;
    }
    
    long long int div;
    long long int div_a, div_b;
    for(int p=0; p<2; p++){
        for(int i=0; i<idx; i++){
            div=p?arr[idx-i-1]:(a+b)/arr[i];
            div_a=a%div;
            div_b=b%div;

            if (div_a==0&&div_b==0) {
                printf("%lld\n", div);
                return 0;
            }
            else{
                if((div_a>div_b?div_b:div_a)<=k) {
                    printf("%lld\n", div);
                    return 0;
                }
            }
            
        }
    }
    

    printf("%d\n", 0);
    return 0;
}
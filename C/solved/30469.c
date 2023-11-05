#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime[100]={0,};
char result[102]={0,};
int can[4]={9,7,3,1};

void prime_init(){
    prime[0]=1;
    prime[1]=1;
    for(int i=2; i<100; i++){
        if(prime[i]==0){
            for(int j=i+i; j<100; j+=i){
                prime[j]=1;
            }
        }
    }
}


void bt(int n, int e){
    if(n==e){
        for(int i=0; i<e+1; i++){
            int ck=result[i]+result[i+1]*10;
            if(prime[ck]==1) return;
        }
        int len=strlen(result);
        for(int i=len-1; i>=0; i--){
            printf("%c", result[i]+'0');
        }
        exit(0);
    }
    else{
        int ck=result[n-1];
        for(int i=0; i<4; i++){
            ck+=10*can[i];
            if(prime[ck]==0){
                result[n]=can[i];
                bt(n+1, e);
            }
            ck-=10*can[i];
        }
    }
}

int main(){
    prime_init();
    int a,b,n;
    scanf("%d %d %d", &a, &b, &n);

    
    if (prime[a]==1){
        printf("%d", -1);
        exit(0);
    }

    if (prime[b]==1){
        printf("%d", -1);
        exit(0);
    }

    
    result[n-1]=a/10;
    result[n-2]=a%10;
    result[1]=b/10;
    result[0]=b%10;

    bt(2, n-2);
    printf("-1");
    
} 
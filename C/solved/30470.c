#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct wt{
    int l;
    int c;
}wt;


wt wood[500002]={0,};
int wood_len=0;
int wood_max=0;

int main(){
    int n;
    scanf("%d", &n);

    int op;
    int x;
    for(int i=0; i<n; i++){
        scanf("%d %d", &op, &x);


        if (op==1){
            wood[wood_len].c=1;
            wood[wood_len++].l=x;
            if (x>wood_max){
                wood_max=x;
            }
        }

        else if (op==2){
            int cut=max(wood_max-x,0);
            if (cut==0){
                wood_len=0;
                wood_max=0;
                continue;
            }
            if(x==0){
                continue;
            }
            if(wood_len==0){
                continue;
            }

            int sum=0;
            while(wood_len>0){
                if(wood[wood_len-1].l>cut){
                    sum+=wood[--wood_len].c;
                }
                else break;
            }

            if (sum>0){
                wood[wood_len].l=cut;
                wood[wood_len++].c=sum;
            }

            if (wood_len==0){
                wood_max=0;
                continue;
            }
            wood_max=wood[wood_len-1].l;
        }

    }


    long long int sum=0;
    for(int i=0; i<wood_len; i++){
        sum+=1LL*wood[i].c*wood[i].l;
    }
    printf("%lld", sum);
    
} 
#include <stdio.h>
#include <stdlib.h>

int cnt=0;
int num[16]={0,};
int used[17]={0,};
int roll[16][2]={
    {1,1},
    {1,1},
    {-1,1},
    {-1,1}, //D
    {1,1},
    {1,1},
    {1,-1},
    {-1,1}, //H
    {1,1},
    {-1,-1},
    {1,-1},
    {1,1}, //L
    {1,-1},
    {-1,-1},
    {1,1},
    {-1,1} //P
};

int sum[8]={5,10,9,0,17,8,11,48};



void back(int n){
    if(n==16){
        for (int i = 4; i < 8; i++){
            if(sum[i]!=0) return;
        }

        for (int i = 0; i < 16; i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
        cnt++;
        return;
    }

    for (int i = 1; i <= 16; i++)
    {
        if(!used[i]){
            num[n]=i;
            used[i]=1;
            sum[n/4] -= i*roll[n][0];
            sum[n%4+4] -= i*roll[n][1];

            if((n+1)%4==0){
                if(sum[n/4]==0) back(n+1);
            }
            else back(n+1);

            sum[n/4] += i*roll[n][0];
            sum[n%4+4] += i*roll[n][1];
            used[i]=0;
            num[n]=0;
        }
    }
    
}

int main(){
    back(0);
    printf("%d",cnt);
}
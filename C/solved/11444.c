#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define div 1000000007

typedef long long int lli;


int fibo(lli x){
    lli n=0, tmp=x;
    lli matrix[65][2][2]={{{1,1},{1,0}}};
    lli resert[2][2]={{1,0},{0,1}};

    while (tmp>0){
        tmp>>=1;
        n++;
    }

    for(lli i=0;i<n;i++){
        lli tmp[2][2]={{0,0},{0,0}};
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    tmp[j][k] += matrix[i][j][l] * matrix[i][l][k];
                }
                tmp[j][k] %= div;
            }
        }
        memcpy(matrix[i+1], tmp, sizeof(tmp));
    }

    lli i=0;
    while(x>0){
        if (x&1){
            lli tmp[2][2]={{0,0},{0,0}};
            for(lli j=0;j<2;j++){
                for(lli k=0;k<2;k++){
                    for(lli l=0;l<2;l++){
                        tmp[j][k] += resert[j][l] * matrix[i][l][k];
                    }
                    tmp[j][k] %= div;
                }
            }
            memcpy(resert, tmp, sizeof(tmp));
        }
        x>>=1;
        i++;
    }


    return resert[0][1];

}

int main(){
    lli n;
    scanf("%lld", &n);

    printf("%d", fibo(n));
}

// 팩토리얼을 행렬로 계산할때 {1,1},{1,0}행렬의 지수 n이 n번쨰 팩토리얼 값인데
// 지수 법칙을 이용해 11을 8+2+1로 나눠서 계산하면 계산 복잡도가 log2N으로 줄어든다
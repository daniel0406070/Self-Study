#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char comb_list[102][102][102]={'\0',};

void plus_large(int n0, int r0, int n1, int r1, int n2, int r2){
    int len_1 = strlen(comb_list[n1][r1]);
    int len_2 = strlen(comb_list[n2][r2]);
    int llen = len_1 > len_2 ? len_1 : len_2;

    for (int i = 0; i < llen; i++) {
        if (comb_list[n1][r1][i] == '\0') {
            if (comb_list[n0][r0][i] == '\0') comb_list[n0][r0][i] = comb_list[n2][r2][i];
            else comb_list[n0][r0][i] += comb_list[n2][r2][i] - '0';
        }
        else if (comb_list[n2][r2][i] == '\0') {
            if (comb_list[n0][r0][i] == '\0') comb_list[n0][r0][i] = comb_list[n1][r1][i];
            else comb_list[n0][r0][i] += comb_list[n1][r1][i] - '0';
        }
        else{
            if (comb_list[n0][r0][i] == '\0') comb_list[n0][r0][i] = comb_list[n1][r1][i] + comb_list[n2][r2][i] - '0';
            else comb_list[n0][r0][i] += comb_list[n1][r1][i] + comb_list[n2][r2][i] - '0' - '0';
        }

        if (comb_list[n0][r0][i] > '9') {
            comb_list[n0][r0][i] -= 10;
            if (comb_list[n0][r0][i+1] == '\0') {
                comb_list[n0][r0][i+1] = '1';
            }
            else{
                comb_list[n0][r0][i+1] += 1;
            }
        }
    }
}

void comb(int n, int r) {
    if (comb_list[n][r][0] == '\0'){
        if (r == 0 || n == r) {
            comb_list[n][r][0] = '1';
        }
        else{
            comb(n-1,r-1);
            comb(n-1,r);
            plus_large(n,r,n-1,r-1,n-1,r);
        }
        
    }
    
}


int main() {
    int n,r,tmp,num[102],div[102];
    scanf("%d %d",&n,&r);

    comb(n,r);
    
    int len = strlen(comb_list[n][r]);

    for (int i = len-1; i >= 0; i--) {
        printf("%c",comb_list[n][r][i]);
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[101][101]={0,};



int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    

}
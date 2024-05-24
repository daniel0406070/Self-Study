#include <stdio.h>

int map[102][102]={0,};

int main(){
    int x1, y1, x2, y2;
    for(int i=0; i<4; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int j=x1; j<x2; j++){
            for(int k=y1; k<y2; k++){
                map[j][k]=1;
            }
        }
    }
    
    int cnt=0;
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            if(map[i][j]==1) cnt++;
        }
    }
    printf("%d", cnt);
}
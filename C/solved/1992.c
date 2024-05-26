#include <stdio.h>
#include <stdlib.h>

int map[64][64];

void quad(int x, int y, int n){
    int flag = 0;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(map[x][y] != map[i][j]){
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        printf("(");
        quad(x, y, n/2);
        quad(x, y+n/2, n/2);
        quad(x+n/2, y, n/2);
        quad(x+n/2, y+n/2, n/2);
        printf(")");
    }
    else{
        printf("%d", map[x][y]);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    quad(0, 0, n);
}
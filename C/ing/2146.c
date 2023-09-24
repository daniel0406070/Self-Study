#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[101][101]={0,};

void find_border(int x, int y){
    if (x<0 || y<0 || x>=n || y>=n) return;
    if (map[x][y]==0) return;
    if (map[x][y]==1) {
        map[x][y]=-1;
        find_border(x-1, y);
        find_border(x+1, y);
        find_border(x, y-1);
        find_border(x, y+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }



}
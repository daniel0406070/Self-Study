#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int board[21][21];
int n;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

long long int move(int cnt){
    long long int max = 0;
    if(cnt == 5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(max < board[i][j]) max = board[i][j];
            }
        }
        return max;
    }

    long long int tmp[21][21];
    memcpy(tmp, board, sizeof(board));
    for(int i=0; i<4; i++){
        int dx = dir[i][0];
        int sx=(dir[i][0] == 0 || dir[i][0] == 1)? 0 : n-1;
        int ex=(dir[i][0] == 0 || dir[i][0] == 1)? n-1: 0;
        int idx_x = sx;

        int dy = dir[i][1];
        int sy=(dir[i][1] == 0 || dir[i][1] == 1)? 0 : n-1;
        int ey=(dir[i][1] == 0 || dir[i][1] == 1)? n-1: 0;
        int idx_y = sy;


        int gap=0;

        while(1){
            //func
            if(board[idx_x][idx_y] >0){
                long long int hit = 0;
                int tmp_x = idx_x;
                int tmp_y = idx_y;
                while(hit==0){
                    tmp_x+=dx;
                    tmp_y+=dy;
                    if(tmp_x>ex && ex>sx || tmp_x<ex && ex<sx || tmp_y>ey && ey>sy || tmp_y<ey && ey<sy) break;
                    hit = board[tmp_x][tmp_y];
                }
                
                if(hit== board[idx_x][idx_y]){
                    board[idx_x-gap*dx][idx_y-gap*dy] = board[idx_x][idx_y] * 2;
                    if(idx_x-gap*dx != idx_x || idx_y-gap*dy != idx_y) board[idx_x][idx_y] = 0;
                    board[tmp_x][tmp_y] = 0;
                }
                else{
                    
                    board[idx_x-gap*dx][idx_y-gap*dy] = board[idx_x][idx_y];
                    if(idx_x-gap*dx != idx_x || idx_y-gap*dy != idx_y) board[idx_x][idx_y] = 0;
                }
            }
            else{
                gap++;
            }



            //idx part
            if(idx_x == ex && idx_y == ey) break;

            idx_x = idx_x + dx;
            idx_y = idx_y + dy;

            if(idx_x > ex && ex>sx || idx_x < ex && ex < sx) {
                idx_y+=1;
                idx_x = sx;
                gap = 0;
            }
            if(idx_y > ey && ey>sy || idx_y < ey && ey < sy) {
                idx_x+=1;
                idx_y = sy;
                gap = 0;
            }
        }    

        // for(int j=0; j<n; j++){
        //     for(int k=0; k<n; k++){
        //         printf("%2lld ", board[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        int ret = move(cnt+1);
        if(max < ret) max = ret;
        memcpy(board, tmp, sizeof(tmp));
    }
    return max;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) scanf("%lld", &board[i][j]);
    }

    printf("%lld\n", move(0));
}

// 다시는 이런 문제 안푼다.
// 쉬운줄 알았는데....
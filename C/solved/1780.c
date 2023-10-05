#include <stdio.h>
#include <stdlib.h>

typedef struct paper_t{
    int minus;
    int zero;
    int plus;
}paper_t;

short int map[2187][2187];

paper_t paper_fn(int x, int y, int n);
paper_t paper_sum(paper_t a, paper_t b);

paper_t paper_fn(int x, int y, int n){
    paper_t paper_tmp = {0,0,0};
    short int check = map[x][y];

    if (n == 1){
        if (check == -1) paper_tmp.minus = 1;
        else if (check == 0) paper_tmp.zero = 1;
        else paper_tmp.plus = 1;
        return paper_tmp;
    }

    int ck = 0;
    for (int i=x; i<x+n; i++){
        for (int j=y; j<y+n; j++){
            if (map[i][j] != check){
                ck = 1;
                break;
            }
        }
    }

    if (ck){
        for(int i=x; i<x+n; i+=n/3)
            for(int j=y; j<y+n; j+=n/3)
                paper_tmp = paper_sum(paper_tmp, paper_fn(i,j,n/3));

        return paper_tmp;
    }
    else{
        if (check == -1) paper_tmp.minus = 1;
        else if (check == 0) paper_tmp.zero = 1;
        else paper_tmp.plus = 1;
        return paper_tmp;
    }
}

paper_t paper_sum(paper_t a, paper_t b){
    paper_t paper_tmp = {0,0,0};
    paper_tmp.minus = a.minus + b.minus;
    paper_tmp.zero = a.zero + b.zero;
    paper_tmp.plus = a.plus + b.plus;
    return paper_tmp;
}



int main(){
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%hd",&map[i][j]);
        }
    }

    paper_t paper = paper_fn(0,0,n);

    printf("%d\n%d\n%d\n",paper.minus,paper.zero,paper.plus);

}
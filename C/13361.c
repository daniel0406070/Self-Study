#include <stdio.h>

int p[250004];
long int rl[250004];
long int rh[250004];

int sl[500004]={0,};
int sh[500004]={0,};

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
}

int main(){
    int n;
    scanf("%d", &n);
    long int tmp_a, tmp_b;
    for(int i = 0; i < n; i++){
        scanf("%ld %ld", &tmp_a, &tmp_b);
        p[i] = i;
        rl[i] = tmp_a>tmp_b ? tmp_b : tmp_a;
        rh[i] = tmp_a>tmp_b ? tmp_a : tmp_b;
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 100002

typedef struct segtree *segtreeptr;
typedef struct segtree{
    int start,end;
    int len;
    short int seg[4*MAX];
} segtree;

segtree aseg;


void init(segtreeptr seg,int len){
    int tmp_len=len;
    len-=1;
    len|=len>>1;
    len|=len>>2;
    len|=len>>4;
    len|=len>>8;
    len|=len>>16;
    len+=1;
    seg->len=len;
    seg->start=len;
    seg->end=len+tmp_len-1;
    for (int i = 1; i <= seg->end; i++){
        seg->seg[i]=1;
    }
}

void set_seg(segtreeptr seg,int idx,int val){ 
    idx+=seg->start;
    int a=val>0?1:(val<0?-1:0);
    while (idx!=0){
        seg->seg[idx]*=a;
        idx/=2;
    }
}

void update_seg(segtreeptr seg,int idx, int val){
    idx+=seg->start;
    int a=val>0?1:(val<0?-1:0);
    if (seg->seg[idx]==a) return;
    else {
        if (a==0){
            seg->seg[idx]=0;
            while (idx!=1){
                idx/=2;
                seg->seg[idx]=seg->seg[idx*2]*seg->seg[idx*2+1];
            }
        }
        else{
            if (seg->seg[idx])seg->seg[idx]*=-1;
            else seg->seg[idx]=a;
            while (idx!=1){
                idx/=2;
                seg->seg[idx]=seg->seg[idx*2]*seg->seg[idx*2+1];
            }
        }
    }
}

int print_seg(segtreeptr seg,int l,int r,int nl,int nr,int idx){
    if (l==nl && r==nr){
        return seg->seg[idx];
    }
    int mid=(nl+nr)/2;
    if (r<=mid){
        return print_seg(seg,l,r,nl,mid,idx*2);
    }
    else if (l>mid){
        return print_seg(seg,l,r,mid+1,nr,idx*2+1);
    }
    else{
        int left=print_seg(seg,l,mid,nl,mid,idx*2);
        int right=print_seg(seg,mid+1,r,mid+1,nr,idx*2+1);
        return left*right;
    }
}


int main(){
    int n,m,x,y;
    short int a;
    char c;
    while(scanf("%d %d",&n,&m)!=EOF){
        init(&aseg,n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            set_seg(&aseg,i,x);
        }
        for(int i=0;i<m;i++){
            scanf(" %c %d %d",&c,&x,&y);
            if(c=='C'){
                update_seg(&aseg,x-1,y);
            }
            else{
                a=print_seg(&aseg,x,y,1,aseg.len,1);
                if(a>0) printf("+");
                else if(a<0) printf("-");
                else printf("0");
            }
        }
        printf("\n");
    }
}
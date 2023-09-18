#include <stdio.h>
#include <stdlib.h>
#define MAX 100002

typedef struct segtree *segtreeptr;
typedef struct segtree{
    int start,end;
    int len;
    int seg[4*MAX];
} segtree;

segtree topseg;
segtree botseg;


void init(segtreeptr seg,int len, int top){
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
    for (int i = 0; i <= seg->end; i++){
        seg->seg[i]=top?0:0x7fffffff;
    }
}

void set_top(segtreeptr seg,int idx,int val){ 
    idx+=seg->start;
    while (idx!=0){
        seg->seg[idx]=val>seg->seg[idx]?val:seg->seg[idx];
        idx/=2;
    }
}

void set_bot(segtreeptr seg,int idx,int val){ 
    idx+=seg->start;
    while (idx!=0){
        seg->seg[idx]=val<seg->seg[idx]?val:seg->seg[idx];
        idx/=2;
    }
}

int print_top(segtreeptr seg,int l,int r,int nl,int nr,int idx){
    if (l==nl && r==nr){
        return seg->seg[idx];
    }
    int mid=(nl+nr)/2;
    if (r<=mid){
        return print_top(seg,l,r,nl,mid,idx*2);
    }
    else if (l>mid){
        return print_top(seg,l,r,mid+1,nr,idx*2+1);
    }
    else{
        int left=print_top(seg,l,mid,nl,mid,idx*2);
        int right=print_top(seg,mid+1,r,mid+1,nr,idx*2+1);
        return left>right?left:right;
    }
}

int print_bot(segtreeptr seg,int l,int r,int nl,int nr,int idx){
    if (l==nl && r==nr){
        return seg->seg[idx];
    }
    int mid=(nl+nr)/2;
    if (r<=mid){
        return print_bot(seg,l,r,nl,mid,idx*2);
    }
    else if (l>mid){
        return print_bot(seg,l,r,mid+1,nr,idx*2+1);
    }
    else{
        int left=print_bot(seg,l,mid,nl,mid,idx*2);
        int right=print_bot(seg,mid+1,r,mid+1,nr,idx*2+1);
        return left<right?left:right;
    }
}




int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    init(&topseg,n,1);
    init(&botseg,n,0);

    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        set_top(&topseg,i,tmp);
        set_bot(&botseg,i,tmp);
    }

    int l,r;
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        printf("%d %d\n",print_bot(&botseg,l,r,1,botseg.len,1),print_top(&topseg,l,r,1,topseg.len,1));
    }

}
// 세그먼트 트리를 합이 아니라 최대,최솟값으로 구현하면 된다.
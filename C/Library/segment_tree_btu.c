#define MAX 1000004


typedef struct {
    int start,end;
    int len;
    int seg[4*MAX];
} segtree;
typedef segtree *segtreeptr;
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
    for (int i = 0; i <= seg->end; i++){
        seg->seg[i]=0;
    }
}

void setval(segtreeptr seg,int idx,int val){ 
    idx+=seg->start;
    while (idx!=0){
        seg->seg[idx]+=val;
        idx/=2;
    }
}
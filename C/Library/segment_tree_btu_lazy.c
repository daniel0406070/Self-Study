#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1100000

long long int seg[4*MAX]={0,};
long long int lazy[4*MAX]={0,};

void lazy_update(int idx,int start,int end){
    lazy[idx*2]+=lazy[idx];
    lazy[idx*2+1]+=lazy[idx];
    seg[idx]+=lazy[idx]*(end-start+1);
    lazy[idx]=0;
}

void insert(int idx,int start,int end,long long int val,int i){
    seg[idx]+=val;
    if (start==end) return;
    int mid=(start+end)/2;
    if (i<=mid) insert(idx*2,start,mid,val,i);
    else insert(idx*2+1,mid+1,end,val,i);
}

void update(int start, int end, int find_start, int find_end, int idx, long long int val){
    if (lazy[idx]!=0) lazy_update(idx,start,end);
    if (find_end<start || end<find_start) return;
    if (find_start<=start && end<=find_end){
        lazy[idx]+=val;
        lazy_update(idx,start,end);
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,find_start,find_end,idx*2,val);
    update(mid+1,end,find_start,find_end,idx*2+1,val);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}

long long int sum(int start,int end,int find_start,int find_end,int idx){
    if (lazy[idx]!=0) lazy_update(idx,start,end);
    if (find_end<start || end<find_start) return 0;
    if (find_start<=start && end<=find_end) return seg[idx];
    int mid=(start+end)/2;
    return sum(start,mid,find_start,find_end,idx*2)+sum(mid+1,end,find_start,find_end,idx*2+1);
}
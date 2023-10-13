#include <stdio.h>
#include <stdlib.h>

int dir[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int danger[4][2] = {
    {1,0},
    {0,-1},
    {-1,0},
    {0,1}
};

typedef struct point{
    int x;
    int y;
} point;

typedef struct typhoon{
    point p;
    int day;
    int dir;
} typhoon;

typedef struct people{
    point p;
    int day;
} people;

typhoon typhoons[200002];
int n,k,r,q;


int main(){
    scanf("%d %d %d %d",&n,&k,&r,&q);
    
    scanf("%d %d %d",&typhoons[0].day,&typhoons[0].p.x,&typhoons[0].p.y);
    for(int i = 1; i < k; i++){
        scanf("%d %d %d",&typhoons[i].day,&typhoons[i].p.x,&typhoons[i].p.y);
        int dx = typhoons[i].p.x - typhoons[i-1].p.x;
        int dy = typhoons[i].p.y - typhoons[i-1].p.y;
        int ddir;

        if(dx == 0){
            if(dy > 0) ddir = 0;
            else ddir = 2;
        }
        else{
            if(dx > 0) ddir = 1;
            else ddir = 3;
        }
        
        typhoons[i-1].dir = ddir;
    }
    typhoons[k-1].dir = typhoons[k-2].dir;

    for(int i=0; i<q; i++){
        people p;
        scanf("%d %d %d",&p.day,&p.p.x,&p.p.y);

        int idx=0;
        int left=0;
        int right=k-1;
        int mid;
        if(p.day==n){
            idx=k-1;
        }
        else{
            while(left<=right){
                mid=(left+right)/2;
                if (typhoons[mid].day>p.day){
                    right=mid-1;
                }
                else if (typhoons[mid+1].day<=p.day){
                    left=mid+1;
                }
                else{
                    idx=mid;
                    break;  
                }
            }
            if (idx!=mid){
                if(typhoons[left].day<=p.day) idx=left;
                else idx=right;
            }
        }
        
        long long int now_x=typhoons[idx].p.x+dir[typhoons[idx].dir][0]*(p.day-typhoons[idx].day);
        long long int now_y=typhoons[idx].p.y+dir[typhoons[idx].dir][1]*(p.day-typhoons[idx].day);

        if ((1LL*p.p.x-now_x)*(1LL*p.p.x-now_x)+(1LL*p.p.y-now_y)*(1LL*p.p.y-now_y)<=1LL*r*r){
            
            long long int ck=(1LL*p.p.x-now_x)*danger[typhoons[idx].dir][0]+(1LL*p.p.y-now_y)*danger[typhoons[idx].dir][1];
            if (ck>0){
                printf("unsafe\n");
            }
            else if (ck==0){
                printf("gori\n");
            }
            else printf("safe\n");
        }
        else printf("gori\n");
        
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[9]= {0,}, t[9]= {0,}, m[9]= {0,};
int z[7]={0,};
int head=0, body=0;
int total=0;
int max_3,can_2,can_3;

int dfs_zhun();
void dfs_zhun2(int tmp_arr[9]);
void dfs_zhun3(int tmp_arr[9]);
void dfs_kus3(int tmp_arr[9]);
void dfs_3(int tmp_arr[9]);
void reset_max();


int main(){
    int n;
    scanf("%d", &n);
    char op[3]={"\0",};
    for (int i=0;i<n;i++){
        scanf("%s", op);
        s[op[0] - '0'-1]++;
    }

    dfs_zhun();
    printf("%d %d", can_2, max_3);

}



int dfs_zhun(){
    total = 0;
    can_2 = 0;
    dfs_zhun2(s);  
    if (can_2) {
        if (total>=4) return 1;
        dfs_3(t);
        if (total>=4) return 1;
        dfs_3(m);
        if (total>=4) return 1;
    }

    total = 0;
    can_2 = 0;
    dfs_zhun2(t);
    if (can_2) {
        if (total>=4) return 1;
        dfs_3(s);
        if (total>=4) return 1;
        dfs_3(m);
        if (total>=4) return 1;
    }

    total = 0;
    can_2 = 0;
    dfs_zhun2(m);
    if (can_2) {
        if (total>=4) return 1;
        dfs_3(s);
        if (total>=4) return 1;
        dfs_3(t);
        if (total>=4) return 1;
    }

}

void reset_max(){
    max_3 = 0;
    can_3 = 0;
}

void dfs_zhun2(int tmp_arr[9]){
    for(int i = 0; i <9; i++)
    {
        if(tmp_arr[i]>=2)
        {
            tmp_arr[i]-=2;
            can_2=1;
            reset_max();
            dfs_kus3(tmp_arr);
            dfs_zhun3(tmp_arr);
            total=total>max_3?total:max_3;
            tmp_arr[i]+=2;
        }
    }
}
void dfs_zhun3(int tmp_arr[9]){
    for(int i = 0; i <7; i++)
    {
        if(tmp_arr[i]&&tmp_arr[i+1]&&tmp_arr[i+2])
        {
            tmp_arr[i]--;
            tmp_arr[i+1]--;
            tmp_arr[i+2]--;
            can_3++;
            max_3=can_3>max_3?can_3:max_3;
            dfs_zhun3(tmp_arr);
            dfs_kus3(tmp_arr);
            can_3--;
            tmp_arr[i]++;
            tmp_arr[i+1]++;
            tmp_arr[i+2]++;
        }
    }
}
void dfs_kus3(int tmp_arr[9]){
    for(int i = 0; i <9; i++)
    {
        if(tmp_arr[i]>=3)
        {
            tmp_arr[i]-=3;
            can_3++;
            max_3=can_3>max_3?can_3:max_3;
            dfs_kus3(tmp_arr);
            dfs_zhun3(tmp_arr);
            can_3--;
            tmp_arr[i]+=3;
        }
    }

}

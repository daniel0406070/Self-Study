#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct connetion{
    int b;
    int len;
} connetion;

typedef struct node *nptr;
typedef struct node{
    connetion con;
    nptr next;
} node;

nptr *arr;
int visited[100002]={0,};

connetion dfs(int start){
    connetion max={0,0};

    nptr tmp = arr[start];
    while(tmp!=NULL){
        if(visited[tmp->con.b]==0){
            visited[tmp->con.b]=1;
            connetion rtn = dfs(tmp->con.b);
            if(rtn.len+tmp->con.len>max.len){
                max.len = rtn.len+tmp->con.len;
                max.b = rtn.b;
            }
        }

        tmp=tmp->next;
    }

    if(max.len==0){
        max.len=0;
        max.b=start;
    }

    return max;
}

int main(){
    int n;
    scanf("%d",&n);

    arr = (nptr*)malloc(sizeof(nptr)*n);

    for(int i=0;i<n;i++){
        int a,b,len;
        scanf("%d",&a);

        a=a-1;
        arr[a] = NULL;
        while(1){
            scanf("%d",&b);
            if(b==-1) break;
            scanf("%d",&len);

            nptr tmp = (nptr)malloc(sizeof(node));
            tmp->con=(connetion){b-1,len};
            if(arr[a]==NULL){
                arr[a]=tmp;
                arr[a]->next=NULL;
            }
            else{
                tmp->next=arr[a];
                arr[a]=tmp;
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     nptr temp = arr[i];
    //     while(temp!=NULL){
    //         printf("%d %d %d\n",i,temp->con.b,temp->con.len);
    //         temp=temp->next;
    //     }
    // }

    visited[0]=1;
    connetion result = dfs(0);

    memset(visited,0,sizeof(visited));
    visited[result.b]=1;
    result = dfs(result.b);

    printf("%d",result.len);

    for(int i=0;i<n;i++){
        nptr temp = arr[i];
        while(temp!=NULL){
            nptr del = temp;
            temp=temp->next;
            free(del);
        }
    }
    free(arr);

}
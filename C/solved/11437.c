#include <stdio.h>
#include <stdlib.h>

#define MAX 100002
#define BIG(x,y) ((x)>(y)?(x):(y))
#define SMALL(x,y) ((x)<(y)?(x):(y))

typedef int size_i;
typedef struct node *nptr;
typedef struct node{
    size_i data;
    nptr next;
} node;

nptr head[MAX];
size_i dp[MAX]={0,};
size_i queqe[MAX];
size_i checklist[MAX]={0,};
int front = 0, rear = 0;

int main(){
    int n,m;
    scanf("%d", &n);
    
    int x,y;
    for (int i = 0; i < n-1; i++){
        scanf("%d %d", &x, &y);
        nptr tmp = (nptr)malloc(sizeof(struct node));
        tmp->data = y;
        tmp->next = head[x];
        head[x] = tmp;

        tmp = (nptr)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = head[y];
        head[y] = tmp;
    }

    queqe[rear++] = 1;
    while (front < rear){
        int cur = queqe[front++];
        for (nptr i = head[cur]; i != NULL; i = i->next){
            if (dp[i->data] == 0){
                dp[i->data] = cur;
                queqe[rear++] = i->data;
            }
        }
    }
    dp[1] = -1;

    scanf("%d", &m); 
    for (int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        
        for (int a = x; a != -1; a = dp[a]){
            checklist[a] = x;
        }

        for (int a = y; a != -1; a = dp[a]){
            if (checklist[a] == x){
                printf("%d\n", a);
                break;
            }
        }
    }
}
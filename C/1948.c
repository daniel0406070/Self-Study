#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10002
#define MAX2 100002

int cnt=0;
int sc,ec,hi=0;
int indegree[MAX]={0,};
int indegree2[MAX]={0,};
int keep[MAX]={0,};
int keep2[MAX]={0,};

int queue[MAX];
int front=0,rear=0;

typedef struct node *nptr;
typedef struct node {
	int t;
	int v;
	int r;
	nptr next;
} node;
nptr graph[MAX] = { NULL, };
nptr graph2[MAX] = { NULL, };

void add_edge(int s, int t, int v) {
	nptr tmp = (nptr)malloc(sizeof(node));
	tmp->t = t;
	tmp->v = v;
	tmp->r = 0;
	tmp->next = graph[s];
	graph[s] = tmp;

	nptr tmp2 = (nptr)malloc(sizeof(node));
	tmp2->t = s;
	tmp2->v = v;
	tmp2->r = 0;
	tmp2->next = graph2[t];
	graph2[t] = tmp2;
}

void enqueue(int x){
    queue[rear++]=x;
    if(MAX-1==rear) rear=0;
}

int dequeue(){
	int tmp=queue[front++];
    if(MAX-1==front) front=0;
	return tmp;
}


void solve(){
	front=0,rear=0;
	enqueue(sc);
	while(front!=rear){
		int now = dequeue();
			
		nptr tmp2 = graph[now];
		while(tmp2!=NULL){
			int next = tmp2->t;
			int value = tmp2->v;
			if(indegree[next]>=1) {
				keep[next]=keep[next]>value+keep[now]?keep[next]:value+keep[now];
				if (indegree[next]==1) enqueue(next);
				indegree[next]--;
			}
			if(tmp2->next!=NULL)tmp2=tmp2->next;
			else tmp2=NULL;
		}
	}
	hi=keep[ec];
	printf("%d\n",keep[ec]);
}



void solve2(){
	front=0,rear=0;
	enqueue(ec);
	while(front!=rear){
		int now = dequeue();
		if(now==sc) {
			continue;
		}
		while(graph2[now]!=NULL){
			int next = graph2[now]->t;
			int value = graph2[now]->v;
			if(indegree2[next]>=1) {
				keep2[next]=keep2[next]>value+keep2[now]?keep2[next]:value+keep2[now];
				if (indegree2[next]==1) enqueue(next);
				indegree2[next]--;
			}
			if (keep[next]+value+keep2[now]==hi) {
				cnt++;
			}
			nptr tmp = graph2[now];
			if(graph2[now]->next!=NULL)graph2[now]=graph2[now]->next;
			else graph2[now]=NULL;
			free(tmp);
		}
	}
	printf("%d",cnt);
}



int main(){
	memset(indegree,0,sizeof(indegree));

	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		add_edge(x,y,z);
		indegree[y]++;
		indegree2[x]++;
		
	}
	scanf("%d %d",&sc,&ec);
	solve();
	solve2();
}
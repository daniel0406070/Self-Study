#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32003

short int indegree[MAX];

typedef struct node *nptr;
typedef struct node {
	int t;
	nptr next;
} node;

nptr graph[MAX] = { NULL, };

void add_edge(int s, int t) {
	nptr tmp = (nptr)malloc(sizeof(node));
	tmp->t = t;
	tmp->next = graph[s];
	graph[s] = tmp;
}

int lenmin = 0;
int pqmin[100002]= { 0, };

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push_min(int x) { //푸쉬
	pqmin[++lenmin] = x;
	int i = lenmin;
	while (i > 1 && pqmin[i] < pqmin[i/2]) {
		swap(&pqmin[i], &pqmin[i/2]);
		i = i/2;
	}	
}

int pop_min() { //팝
	if (lenmin == 0) {
		return 0;
	}
	int ret = pqmin[1];
	pqmin[1] = pqmin[lenmin--];
	int i = 1;
	while (i * 2 <= lenmin) {
		int child;
		if (i * 2 + 1 > lenmin) child = i * 2;
		else child =  pqmin[i * 2] < pqmin[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (pqmin[i] < pqmin[child]) break;
		swap(&pqmin[i], &pqmin[child]);
		i = child;
	}
	return ret;
}

int main(){
	memset(indegree,0,sizeof(indegree));

	int n,m;
	scanf("%d %d",&n,&m);
	
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		add_edge(x,y);
		indegree[y]++;
	}

	for(int i=1;i<=n;i++){
		if(indegree[i]==0) push_min(i);
	}

	while(lenmin>0){
		int now = pop_min();
		printf("%d ",now);
		while(graph[now]!=NULL){
			int next = graph[now]->t;
			indegree[next]--;
			if(indegree[next]==0) push_min(next);
			nptr tmp = graph[now];
			if(graph[now]->next!=NULL)graph[now]=graph[now]->next;
			else graph[now]=NULL;
			free(tmp);
		}
	}
}
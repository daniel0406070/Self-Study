#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200002

int lenmin = 0;
int pqmin[MAX]= { 0, };

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

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);
    
	int tmp[MAX][2];
	
	int s,t;
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &t);
        tmp[i][0] = s;
		tmp[i][1] = t;
    }

	qsort(tmp, n, sizeof(tmp[0]), compare);

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			push_min(tmp[i][1]);
			continue;
		}
		if (tmp[i][0] >= pqmin[1]) {
			pop_min();
		}
		push_min(tmp[i][1]);
	}
	printf("%d", lenmin);

}
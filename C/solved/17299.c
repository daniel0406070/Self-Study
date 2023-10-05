#include <stdio.h>
#include <stdlib.h>

#define MAX 1000004
typedef struct {
    int item[MAX];
    int top;
} stack;
stack astack;
stack bstack;

int NGE[MAX];
int tmp_num[MAX];
int f[MAX]={0,};

void push(stack* s, int item);
int pop(stack* s);
int is_empty(stack* s);
int is_full(stack* s);

void push(stack* s, int item){
    if(is_full(s)) return;
    s->item[++(s->top)]=item;
}

int pop(stack* s){
    if(is_empty(s)) return 0;
    return s->item[(s->top)--];
}

int is_empty(stack* s){
    return (s->top==-1);
}

int is_full(stack* s){
    return (s->top==MAX-1);
}


int main() {
	astack.top = -1;
	bstack.top = -1;
	int n;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
        f[tmp]++;
        tmp_num[i]=tmp;
    }
    for (int i = 0; i < n; i++) {
        tmp=tmp_num[i];
		push(&astack, tmp);
		if (i == 0) {
			push(&bstack, i);
			continue;
		}
		while (1) {
			if (is_empty(&bstack)) {
				push(&bstack, i);
				break;
			}
			if (f[tmp] > f[astack.item[bstack.item[bstack.top]]]) {
				NGE[bstack.item[bstack.top]] = tmp;
				pop(&bstack);
			}
			else {
				push(&bstack, i);
				break;
			}
		}
	}
	while (!is_empty(&bstack)) {
		NGE[bstack.item[bstack.top]] = -1;
		pop(&bstack);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", NGE[i]);
	}
}

// 오큰수에서 조금 변화만 주면 쉽게 풀린다
// 출현 빈도 저장 후 푸쉬
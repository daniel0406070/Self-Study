int lenmax = 0;
int pqmax[100002]= { 0, };

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push_max(int x) { //푸쉬
	pqmax[++lenmax] = x;
	int i = lenmax;
	while (i > 1 && pqmax[i] > pqmax[i/2]) {
		swap(&pqmax[i], &pqmax[i/2]);
		i = i/2;
	}	
}

int pop_max() { //팝
	if (lenmax == 0) {
		return 0;
	}
	int ret = pqmax[1];
	pqmax[1] = pqmax[lenmax--];
	int i = 1;
	while (i * 2 <= lenmax) {
		int child;
		if (i * 2 + 1 > lenmax) child = i * 2;
		else child =  pqmax[i * 2] > pqmax[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (pqmax[i] > pqmax[child]) break;
		swap(&pqmax[i], &pqmax[child]);
		i = child;
	}
	return ret;
}
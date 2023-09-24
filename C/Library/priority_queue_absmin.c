#include <stdlib.h>

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
	while (i > 1 && (abs(pqmin[i]) < abs(pqmin[i/2]) || (abs(pqmin[i]) == abs(pqmin[i/2]) && pqmin[i] < pqmin[i/2]) ) ) {
		swap(&pqmin[i], &pqmin[i/2]);
		i = i/2;
	}	
}

int pop_min() { //팝
	if (lenmin == 0) {
		return 0;
	}
	int ret = pqmin[1];
	pqmin[1] = pqmin[lenmin];
	lenmin--;
	int i = 1;
	while (i * 2 <= lenmin) {
		int child;
		if (i * 2 + 1 > lenmin) {
			child = i * 2;
		}
		else {
			if (abs(pqmin[i * 2]) < abs(pqmin[i * 2 + 1]) || (abs(pqmin[i * 2]) == abs(pqmin[i * 2 + 1]) && pqmin[i * 2] < pqmin[i * 2 + 1])) {
				child = i * 2;
			}
			else {
				child = i * 2 + 1;
			}
		}
		if (abs(pqmin[i]) < abs(pqmin[child]) || (abs(pqmin[i]) == abs(pqmin[child]) && pqmin[i] < pqmin[child])) {
			break;
		}
		swap(&pqmin[i], &pqmin[child]);
		i = child;
	}
	
	return ret;
}
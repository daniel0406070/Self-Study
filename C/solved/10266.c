//pi[i]는 prefix==suffix가 될수있는 최대길이를 가지는 배열
//이를 통해 그사이를 건너 뛸수 있다.
// n은 text의 길이, m은 pattern의 길이 (strlen 반복 방지)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kmp_size 1000005

int f[kmp_size]={0,};

void FailureFunction(int m, int* pattern)
{

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) {
			f[i] = ++j;
		} else {
			f[i] = 0;
		}
	}
}

int kmp(int n, int m, int* text, int* pattern){

	int i = 0;
	int j = 0;
	
    for(int i=0; i<n; i++){
        while (j > 0 && text[i] != pattern[j]) j = f[j - 1];

        if (text[i] == pattern[j]) {
            if(j==m-1){
                return i-j;
            }else{
                j++;
            }
        }
    }
    return -1;
}

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int *clock_a=(int*)malloc(sizeof(int)*n);
    int *clock_b=(int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        scanf("%d", &clock_a[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &clock_b[i]);
    }

    qsort(clock_a, n, sizeof(int), cmp);
    qsort(clock_b, n, sizeof(int), cmp);

    int tmp=clock_a[0];
    for(int i=0; i<n-1; i++){
        clock_a[i]=clock_a[i+1]-clock_a[i];
    }
    clock_a[n-1]=360000-clock_a[n-1]+tmp;

    tmp=clock_b[0];
    for(int i=0; i<n-1; i++){
        clock_b[i]=clock_b[i+1]-clock_b[i];
    }
    clock_b[n-1]=360000-clock_b[n-1]+tmp;
    
    clock_b=realloc(clock_b, sizeof(int)*2*n);
    memcpy(clock_b+n, clock_b, sizeof(int)*n);

    FailureFunction(n, clock_a);
    tmp = kmp(2*n, n, clock_b, clock_a);

    if(tmp==-1) printf("impossible");
    else printf("possible");

}
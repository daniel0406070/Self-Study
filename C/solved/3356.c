#include <stdio.h>
#include <string.h>

#define kmp_size 1000005

int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int main(){
    int n;
    char pattern[kmp_size];

    scanf("%d", &n);
    scanf("%s", pattern);
    // n = strlen(pattern);

    FailureFunction(n, pattern);

    // for(int i=0; i<n; i++){
    //     printf("%d ", f[i]);
    // }
    // printf("\n");

    printf("%d\n", n-f[n-1]);
}
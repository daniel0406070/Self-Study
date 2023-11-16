#include <stdio.h>
#include <string.h>

#define kmp_size 500005

int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int main(){
    char s[kmp_size];
    scanf("%s", s);

    int k;
    scanf("%d", &k);

    int n = strlen(s);

    FailureFunction(n, s);

    printf("%lld",1LL*(n-f[n-1])*k+f[n-1]);
}

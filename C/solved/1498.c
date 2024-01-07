#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char pattern[1000005];
    scanf("%s", pattern);

    int m = strlen(pattern);   
    FailureFunction(m, pattern);

    for(int i=1; i<=m; i++){

        if(f[i-1]==0) continue;
        if(i%(i-f[i-1])!=0) continue;

        printf("%d %d\n", i, i/(i-f[i-1]));
    }
}
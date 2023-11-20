#include <stdio.h>
#include <string.h>

#define kmp_size 5005

int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int main(){
    char pattern[kmp_size];
    scanf("%s", pattern);

    int m=strlen(pattern);

    int max=0;
    for(int i=0; i<m-1; i++){
        FailureFunction(m-i, pattern+i);
        for(int j=0; j<m-i; j++){
            if(max<f[j]) max=f[j];
        }
    }



    printf("%d", max);
}
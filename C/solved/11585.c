#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *f;

int gcd(int a, int b){
    int r = 1;
    while(r!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void FailureFunction(int m, char* pattern){
    f = (int*)malloc(sizeof(int)*m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

void kmp(int n, int m, char* text, char* pattern){

	int i = 0;
	int j = 0;

    int *kmp_idx_arr=malloc(sizeof(int)*n);
    int kmp_count=0;

    for(int i=0; i<n; i++){
        while (j > 0 && text[i] != pattern[j]) j = f[j - 1];

        if (text[i] == pattern[j]) {
            if(j==m-1){
                kmp_idx_arr[kmp_count]=i-j;
                (kmp_count)++;
                j=f[j];
            }
            else j++;
        }
    }

    // int a=1;
    int a=gcd(kmp_count, m);
    printf("%d/%d\n", kmp_count/a, m/a);


}

int main(){
    int n;
    scanf("%d", &n);

    char* text=(char*)malloc(sizeof(char)*n*2-1);
    char* pattern=(char*)malloc(sizeof(char)*n); 

    for(int i = 0; i < n; i++){
        scanf(" %c", &pattern[i]);
    }

    for(int i = 0; i < n; i++){
        scanf(" %c", &text[i]);
    }

    memcpy(text+n, text, sizeof(char)*n-1);
    FailureFunction(n, pattern);
    kmp(2*n-1, n, text, pattern);

    free(f);
    free(text);
    free(pattern);
}
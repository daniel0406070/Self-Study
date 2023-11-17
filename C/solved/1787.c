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

int dp[kmp_size]={0,};

int main(){
    int n;
    scanf("%d", &n);

    char s[kmp_size];
    scanf("%s", s);

    FailureFunction(n, s);

    int ans = 0;
    dp[0] = 0;
    for(int i=1; i<n; i++){
        dp[i] = dp[f[i-1]] + 1;
        ans += dp[i];
    }

    for(int i=0; i<n; i++) printf("%d ", f[i]);
    printf("\n");
    for(int i=0; i<n; i++) printf("%d ", dp[i]);
    printf("\n");

    printf("%d", ans);
}

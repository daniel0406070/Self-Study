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

    long long int ans = 0;
    dp[0] = 0;
    for(int i=1; i<n; i++){
        if(f[i]==0) dp[i] = 0;
        else{
            if (dp[f[i]-1] == 0) dp[i] = f[i];
            else dp[i] = dp[f[i]-1];

        }

        if(dp[i] > 0) ans += i-dp[i]+1;
    }

    // for(int i=0; i<n; i++) printf("%d ", dp[i]);
    // printf("\n");

    // for(int i=0; i<n; i++) printf("%d ", f[i]);
    // printf("\n");

    printf("%lld", ans);
}

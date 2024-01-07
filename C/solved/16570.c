#include <stdio.h>
#include <string.h>

#define kmp_size 1000005

int f[kmp_size]={0,};

void FailureFunction(int m, int* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int main(){
    int n;
    scanf("%d", &n);

    int pattern[kmp_size];
    for(int i=0; i<n; i++){
        scanf("%d", &pattern[n-i-1]);
    }

    FailureFunction(n, pattern);
    int max=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(max<f[i]){
            max=f[i];
            cnt=1;
        }
        else if(max==f[i]) cnt++;
    }

    if(max==0) printf("-1\n");
    else printf("%d %d\n", max, cnt);
}
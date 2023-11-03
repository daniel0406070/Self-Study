#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kmp_size 1000005

int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern)
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

int main(){
    char text[kmp_size];
    scanf("%s", text);
    while(text[0]!='.'){
        int n=strlen(text);
        FailureFunction(n, text);

        // for(int i=0; i<n; i++){
        //     printf("%d ", f[i]);
        // }
        // printf("\n");

        int k=n-f[n-1];
        if(n%k==0){
            printf("%d\n", n/k);
        }else{
            printf("1\n");
        }

        scanf("%s", text);
    }
    

    
}

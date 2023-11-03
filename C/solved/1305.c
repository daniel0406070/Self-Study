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
    int m;
    scanf("%d", &m);
    
    char* text;
    text = (char*)malloc(sizeof(char)*m);
    scanf("%s", text);

    

    FailureFunction(m, text);

    int max=0;
    for(int i=0; i<m; i++){
        if (max<f[i]){
            max=f[i];
        }
    }

    // 

    for(int i=m-1; i>=0; i--){
        max=(max>f[i])?max:f[i];
        if (f[i]==0){
            printf("%d",i+1);
            break;
        }

        if (f[i]!=f[i-1]+1){
            if (f[m-1]!=max){
                printf("%d", i-1);
                return 0;
            }
            printf("%d", i);
            break;
        }
    }
}

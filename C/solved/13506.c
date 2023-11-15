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

int kmp(int n, int m, char* text, char* pattern){

	int i = 0;
	int j = 0;
    for(int i=0; i<n; i++){
        while (j > 0 && text[i] != pattern[j]) j = f[j - 1];

        if (text[i] == pattern[j]) {
            if(j==m-1) return i-j;
            else j++;
        }
    }
    return -1;
}

char str[kmp_size];

int main(){
    scanf("%s", str);

    int len=strlen(str);
    FailureFunction(len, str);

    int camal=f[len-1];
    for(int i=camal; i>0; i--){
        int ck=1;
        for(int j=0; j<i; j++){
            if(str[j]!=str[len-i+j]) ck=0;
        }
        if(ck==0) continue;

        FailureFunction(i, str);

        int idx=kmp(len-2, i, str+1, str);
        if(idx==-1) continue;

        for(int j=0; j<i; j++){
            printf("%c", str[j]);
        }
        return 0;
    }
    printf("-1");
}
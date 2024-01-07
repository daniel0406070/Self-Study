#include <stdio.h>
#include <string.h>

#define kmp_size 1000005

typedef struct copy{
    int s;
    int e;
} copy;

copy copy_arr
int f[kmp_size]={0,};


void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

void kmp(int n, int m, char* text, char* pattern){

	int i = 0;
	int j = 0;

    int kmp_idx_arr[kmp_size]={0,};
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

    for(int i=0; i<kmp_count; i++){
        if (kmp_count[kmp_idx_arr[i]]==0){
            
        }
    }
    
}

int main(){
    char text[kmp_size];
    int n;

    scanf("%s", text);
    scanf("%d", &n);

    char pattern[kmp_size];
    for(int i=0; i<n; i++){
        scanf("%s", pattern);
        FailureFunction(strlen(pattern), pattern);
        kmp(strlen(text), strlen(pattern), text, pattern);
    }
}
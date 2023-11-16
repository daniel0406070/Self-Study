#include <stdio.h>
#include <string.h>

#define kmp_size 100005

int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

//모든 부분을 탐색
int kmp(int n, int m, char* text, char* pattern){

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
    return kmp_count;
}

int main(){
    char a[kmp_size]={0,};
    char b[kmp_size*2]={0,};

    scanf("%s", a);
    scanf("%s", b);
    int len_a=strlen(a);
    int len_b=strlen(b);
    memcpy(b+len_b, b, len_b);

    FailureFunction(len_a, a);
    printf("%d", kmp(len_b*2-1, len_a, b, a));
}
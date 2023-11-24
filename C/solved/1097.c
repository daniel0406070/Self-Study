#include <stdio.h>
#include <string.h>

#define kmp_size 1000

int f[kmp_size]={0,};
char text[8][kmp_size];
int n;
int k;
int pass=0;
char magic_word[kmp_size];
int visited[8]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int kmp(int m,  char* pattern){

    int n = m*2-1;
    char text[n];
    memcpy(text, pattern, sizeof(char)*m);
    memcpy(text+m, pattern, sizeof(char)*(m-1));
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

void make_magic(int t,int idx){
    if(t==n){
        magic_word[idx]='\0';
        FailureFunction(idx, magic_word);
        int kmp_idx=kmp(idx, magic_word);
        if(kmp_idx==k){
            pass+=1;
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]==1) continue;
        else{
            memcpy(magic_word+idx, text[i], sizeof(char)*strlen(text[i]));
            visited[i]=1;
            make_magic(t+1, idx+strlen(text[i]));
            visited[i]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", text[i]);
    }
    scanf("%d", &k);

    memcpy(magic_word, text[0], sizeof(char)*strlen(text[0]));
    visited[0]=1;
    make_magic(1, strlen(text[0]));

    printf("%d\n", pass*n);
}
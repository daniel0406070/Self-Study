#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FailureFunction(int n, int m, int* pattern, int* f){
    memset(f, 0, sizeof(int)*m);

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int kmp(int n, int m, int* text, int* pattern, int* f){

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

int kmp_rev(int n, int m, int* text, int* pattern, int* f){

    int i = 0;
    int j = 0;
    for(int i=n-1; i>=0; i--){
        while (j > 0 && text[i] != pattern[j]) j = f[j - 1];

        if (text[i] == pattern[j]) {
            if(j==m-1) return i;
            else j++;
        }
    }
    return -1;
}

void make_num(int len_a, int len_b, int* a, int* b, int** num, int reverse){
    *num=(int*)malloc(sizeof(int)*(len_a+len_b));
    memcpy(*num, a, sizeof(int)*len_a);
    if(reverse==0) memcpy((*num)+len_a, b, sizeof(int)*len_b);
    else{
        for(int i=0; i<len_b; i++){
            (*num)[len_a+len_b-1-i]=b[i];
        }
    }
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int len[101]={0,};

    int** tmp_num;
    int* num;
    int* num_f;

    int virus_count=0;
    int* virus[3000]={0,};
    int** virus_f;

    

    tmp_num=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &len[i]);
        tmp_num[i]=(int*)malloc(sizeof(int)*len[i]);
        for(int j=0; j<len[i]; j++){
            scanf("%d", &tmp_num[i][j]);
        }
    }

    
    // for(int i=0; i<len[0]+2*len[1]; i++){
    //     printf("%d ", num[i]);
    // }
    // printf("\n");
    for(int reverse=0; reverse<2; reverse++){
        make_num(len[0], len[1], tmp_num[0], tmp_num[1], &num, reverse);
        for(int i=0; i<len[0]; i++){
            num_f=(int*)malloc(sizeof(int)*(len[0]+len[1]-i));
            FailureFunction(i, len[0]+len[1]-i, num+i, num_f);
            for(int j=0; j<len[0]+len[1]-i; j++){
                if(num_f[j]==k){
                    virus[virus_count]=(int*)malloc(sizeof(int)*k);
                    memcpy(virus[virus_count], num+i+j-k+1, sizeof(int)*k);
                    virus_count++;
                }
            }
        }
    }

    
    virus_f=(int**)malloc(sizeof(int*)*virus_count);
    for(int i=0; i<virus_count; i++){
        virus_f[i]=(int*)malloc(sizeof(int)*k);
        FailureFunction(k, k, virus[i], virus_f[i]);
    }

    for(int i=2; i<n; i++){
        for(int j=0; j<virus_count; j++){
            int idx=kmp(len[i], k, tmp_num[i], virus[j], virus_f[j]);
            int idx_rev=kmp_rev(len[i], k, tmp_num[i], virus[j], virus_f[j]);
            if(idx==-1&&idx_rev==-1){
                virus[j]=virus[virus_count-1];
                virus_f[j]=virus_f[virus_count-1];
                virus_count--;
                j--;
            }
        }
    }

    
    if (virus_count==0) printf("NO\n");
    else printf("YES\n");

    free(num);
    free(num_f);
    for(int i=0; i<n; i++){
        free(tmp_num[i]);
    }
    free(tmp_num);
    for(int i=0; i<virus_count; i++){
        free(virus[i]);
        free(virus_f[i]);
    }
    free(virus_f);
}


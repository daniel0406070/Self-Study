#include <stdio.h>
#include <string.h>

#define kmp_size 510000

int c_to_d[124]={0,};
char d_to_c[64]={0,};
int f[kmp_size]={0,};

void FailureFunction(int m, char* pattern){

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];

		if (pattern[i] == pattern[j]) f[i] = ++j;
        else f[i] = 0;
	}
}

int kmp(int n, int m, char* text, char* pattern, int shift){

	int i = 0;
	int j = 0;

    int kmp_idx_arr[kmp_size]={0,};
    int kmp_count=0;

    for(int i=0; i<n; i++){
        while (j > 0 && text[i] != d_to_c[c_to_d[pattern[j]]+shift]) j = f[j - 1];

        if (text[i] == d_to_c[c_to_d[pattern[j]]+shift]) {
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
    int t;
    scanf("%d", &t);

    char text[kmp_size]={0,};
    char pattern[kmp_size]={0,};

    while(t--){
        memset(f, 0, sizeof(f));
        memset(text, 0, sizeof(text));
        memset(pattern, 0, sizeof(pattern));
        memset(c_to_d, 0, sizeof(c_to_d));
        memset(d_to_c, 0, sizeof(d_to_c));

        scanf("%s", d_to_c);
        int d_to_c_len=strlen(d_to_c);
        for(int i=0; i<d_to_c_len; i++){
            d_to_c[i+d_to_c_len]=d_to_c[i];
            c_to_d[d_to_c[i]]=i;
        }
        
        scanf("%s", pattern);
        scanf("%s", text);

        int n=strlen(text);
        int m=strlen(pattern);

        FailureFunction(m, pattern);

        int tmp;
        int shift_arr[70]={0,};
        int shift_count=0;
        for(int i=0; i<d_to_c_len; i++){
            tmp=kmp(n, m, text, pattern, i);
            if (tmp==1) {
                shift_arr[shift_count]=i;
                shift_count++;
            }
        }

        if(shift_count==0) printf("no solution\n");
        else if(shift_count==1) printf("unique: %d\n", shift_arr[0]);
        else {
            printf("ambiguous:");
            for(int i=0; i<shift_count; i++){
                printf(" %d", shift_arr[i]);
            }
            printf("\n");
        }
    }
}
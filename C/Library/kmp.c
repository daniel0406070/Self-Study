//pi[i]는 prefix==suffix가 될수있는 최대길이를 가지는 배열
//이를 통해 그사이를 건너 뛸수 있다.
// n은 text의 길이, m은 pattern의 길이 (strlen 반복 방지)

#include <stdio.h>
#include <string.h>

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
            }else{
                j++;
            }
        }
    }

    // printf("%d\n", kmp_count);
    // for(int i=0; i<kmp_count; i++){
    //     printf("%d ", kmp_idx_arr[i]+1);
    // } 
    // kmp_count와 kmp_idx_arr는 전역 변수로 쓰던지 알아서

}
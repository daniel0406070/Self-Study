//pi[i]는 prefix==suffix가 될수있는 최대길이를 가지는 배열
//이를 통해 그사이를 건너 뛸수 있다.

#include <stdio.h>
#include <string.h>
#define kmp_size 1000

int f[kmp_size];

void FailureFunction(char* pattern)
{
	f[0] = 0;
	int i = 1;
	int j = 0;
    int len = strlen(pattern);

	while (i < len)
	{
		if (pattern[i] == pattern[j])
		{
			f[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = f[j - 1];
		else
		{
			f[j] = 0;
			i++;
		}
	}
}

int kmp(char* text, char* pattern){
	int n = strlen(text);
	int m = strlen(pattern);
    FailureFunction(pattern);

	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (text[i] == pattern[j])
			if (j == m - 1)
				return i - j;
			else
			{
				i++;
				j++;
			}
		else
		{
			if (j > 0)
				j = f[j - 1];
			else
				i++;
		}
	}

	return -1;
}

int main(){
    char text[kmp_size];
    char pattern[kmp_size];
    scanf("%[^\n]s", text);
    scanf("%s", pattern);

    int kmp_count = 0;
    int kmp_idx_arr[kmp_size]={0,};

    int kmp_idx = kmp(text, pattern);

    while(kmp_idx != -1){
        kmp_idx_arr[kmp_count++] = kmp_idx+1;
        kmp_idx = kmp(text + kmp_idx + 1, pattern);
    }
    
    printf("%d\n", kmp_count);
    for(int i=0; i<kmp_count; i++){
        printf("%d ", kmp_idx_arr[i]);
    }

    return 0;
}
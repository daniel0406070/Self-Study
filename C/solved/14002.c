#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000002

typedef long long int size_i;

int dp[MAX];
int orginal[MAX];
int record[MAX];
int idx, end;

int bsc(long long int t) {
	int m, l = 0, r = end;
	while (l < r) {
		m = (l+r)/2;
		if (dp[m] < t) l = m+1;
		else r = m;
	}
	return r;
}

int main() {
	idx = -1;
	end = -1;

	int n;
	long long int tmp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
        orginal[i] = tmp;
		if (idx==-1) {
			idx++;
			end++;
			dp[0] = tmp;
			continue;
		}

		if (dp[idx] < tmp) {
			if (idx+1>end || dp[idx+1] > tmp){
				dp[++idx] = tmp;
				end=end<idx?idx:end;
			}
			else {
				idx=bsc(tmp);
				if (idx==end) idx=dp[idx]<tmp?idx+1:idx;
				dp[idx] = tmp;
				end=end<idx?idx:end;
			}
		}
		else {
			idx=bsc(tmp);
			dp[idx] = tmp;
		}
        
        record[i] = idx;
	}
	
	printf("%d\n", end+1);
    int cnt = end;
    for (int i = n-1; i >= 0; i--) {
        if (record[i] == cnt) {
            dp[cnt] = orginal[i];
            cnt--;
        }
    }

    for (int i = 0; i <= end; i++) {
        printf("%d ", dp[i]);
    }

}
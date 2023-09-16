#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100006
int item[MAX];
int len[MAX];
int top=-1;


void push(int x);
int pop();
int is_empty();
int is_full();

void push(int x){
    if(is_full()) return;
    item[++top]=x;
}

int pop(){
    if(is_empty()) return 0;
    return item[top--];
}

int is_empty(){
    return top==-1;
}

int is_full(){
    return top==MAX-1;
}

int main() {
    int n;
    scanf("%d", &n);
	while (n!=0){
		top=-1;
		int height;
		long long int ans = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &height);
			if (is_empty()){
				push(height);
				len[top]=1;
				ans= ans > height*len[top] ? ans : height*len[top];
			}
			else{
				if (height >= item[top]){
					push(height);
					len[top]=1;
				}
				else{
					while(!is_empty() && height < item[top]){
						ans= ans > (long long int)(item[top])*(long long int)(len[top]) ? ans : (long long int)(item[top])*(long long int)(len[top]);
						len[top-1] += len[top];
						pop();
					}
					push(height);
					if (top!=0) len[top-1]-=len[top];
					len[top]+=1;
				}
			}
		}
		while(top!=0){
			ans= ans > (long long int)(item[top])*(long long int)(len[top]) ? ans : (long long int)(item[top])*(long long int)(len[top]);
			len[top-1] += len[top];
			pop();
		}
		ans = ans > (long long int)(item[top])*(long long int)(len[top]) ? ans : (long long int)(item[top])*(long long int)(len[top]);

		printf("%lld\n", ans);
		scanf("%d", &n);
	}
}


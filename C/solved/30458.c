#include <stdio.h>

int main(){
    int alpha[26]={0,};
    int n;
    char c[200002];
    int mid=-1;
    scanf("%d", &n);
    scanf("%s", c);
    for(int i=0; i<n; i++){
        alpha[c[i]-'a']++;
    }
    if(n%2==1) mid=c[n/2]-'a';

    int odd=0;
    for(int i=0; i<26; i++){
        if(alpha[i]%2==1) odd++;
    }

    if(odd<=1){
        if(n%2==0) printf("Yes");
        else if(alpha[mid]%2==1) printf("Yes");
        else printf("No");
    }
    else printf("No");
    
}
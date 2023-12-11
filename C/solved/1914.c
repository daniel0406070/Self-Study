#include <stdio.h>

int n;
char cnt[104]= {'\0',};
int idx = 0;

void hanoi(int t, char from, char tmp, char to){
    if(t == 1){
        printf("%c %c\n", from, to);
    }
    else{
        hanoi(t-1, from, to, tmp);
        printf("%c %c\n", from, to);
        hanoi(t-1, tmp , from, to);
    }
}

int main(){
    scanf("%d", &n);

    cnt[0] = '0';
    for(int i=0; i<n; i++){
        for(int j=0; cnt[j]!='\0'; j++){
            cnt[j]=(cnt[j]-'0')*2+'0';
        }
        cnt[0]++;

        for(int j=0; cnt[j]!='\0'; j++){
            while(cnt[j]>'9'){
                if(cnt[j+1]=='\0') cnt[j+1] = '0';
                cnt[j+1]++;
                cnt[j]-=10;
            }
        }
    }
    for(int i=0; cnt[i]!='\0'; i++) idx = i;
    for(int i=idx; i>=0; i--) printf("%c", cnt[i]);
    printf("\n");

    if(n<21) hanoi(n, '1', '2', '3');
}
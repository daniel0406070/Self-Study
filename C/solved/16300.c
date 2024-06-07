#include <stdio.h>
#define isupper(x) (x>='A' && x<='Z')
#define isnum(x) (x>='0' && x<='9')

int a[27]={0,};
int b[27]={0,};

void parse(int *arr, char *str){
    char tmp=0;
    int dup=0;
    char c;
    while(1){
        c=*str++;
        
        if(isupper(c)){
            if(tmp) arr[tmp-'A'] += !dup?1:dup;
            dup=0;
            tmp = c;
        }
        else if(isnum(c)){
            dup = dup*10 + c-'0';
        }
        else break;
    }
    if(tmp) arr[tmp-'A'] += !dup?1:dup;
}

int main(){
    char str[2560];
    scanf("%s", str);
    parse(a, str);

    int n;
    scanf("%d", &n);
    for(int i=0; i<26; i++) a[i]*=n;

    scanf("%s", str);
    parse(b, str);

    // for(int i=0; i<26; i++) printf("%c %d %d\n", i+'A', a[i], b[i]);

    for(int i=0; i<26; i++) if(b[i]) a[i]/=b[i];

    int min=0x7fffffff;
    for(int i=0; i<26; i++){
        if(b[i] && a[i]<min) min=a[i];
    }
    if(min==0x7fffffff) min=0;

    printf("%d", min);
}
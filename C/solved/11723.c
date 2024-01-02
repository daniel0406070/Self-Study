#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int ans=0;
    char op[10];
    int tmp;
    for (int i = 0; i < n; i++){
        scanf("%s %d",op,&tmp);

        // printf("%s %d\n",op,tmp);
        switch (op[1])
        {
        case 'd':
            ans|=1<<tmp;
            break;
        case 'e':
            ans&=~(1<<tmp);
            break;
        case 'h':
            printf("%d\n",(ans&(1<<tmp))?1:0);
            break;
        case 'o':
            ans^=1<<tmp;
            break;
        case 'l':
            ans=(1<<21)-1;
            break;
        case 'm':
            ans=0;
            break;
        default:
            break;
        }
        
    }   
}
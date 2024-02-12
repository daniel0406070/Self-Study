#include <stdio.h>

int stack[100];
int top = -1;

void push(int n){
    stack[++top] = n;
}

int pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int main(){
    char str[102];
    while(1){
        fgets(str, 102, stdin);
        // printf("%s", str);
        if(str[0] == '.') break;

        int flag = 1;
        for(int i = 0; str[i] != '.'; i++){
            if(str[i] == '(' || str[i] == '[') push(str[i]);
            else if(str[i] == ')'){
                if(pop() != '('){
                    flag = 0;
                    break;
                }
            }
            else if(str[i] == ']'){
                if(pop() != '['){
                    flag = 0;
                    break;
                }
            }
        }

        if(flag && top == -1) printf("yes\n");
        else{
            printf("no\n");
            top = -1;
        }
    }
}
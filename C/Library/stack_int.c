#define MAX 1000004
int item[MAX];
int top;

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
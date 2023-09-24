#define MAX 1000002
typedef struct {
    char item[MAX];
    int top;
} stack;
stack astack;

void push(stack* s, char item);
char pop(stack* s);
int is_empty(stack* s);
int is_full(stack* s);

void push(stack* s, char item){
    if(is_full(s)) return;
    s->item[++(s->top)]=item;
}

char pop(stack* s){
    if(is_empty(s)) return '\0';
    return s->item[(s->top)--];
}

int is_empty(stack* s){
    return (s->top==-1);
}

int is_full(stack* s){
    return (s->top==MAX-1);
}
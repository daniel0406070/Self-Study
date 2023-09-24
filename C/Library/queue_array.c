#define MAX 32003

int queue[MAX];
int front=0,rear=0;

void enqueue(int x){
    queue[rear++]=x;
    if(MAX-1==rear) rear=0;
}

int dequeue(){
    int a = queue[front++];
    if(MAX-1==front) front=0;
		return a;
}
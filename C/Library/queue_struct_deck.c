typedef struct node *qPointer;
typedef struct node{
	char item[5];
	qPointer next;
	qPointer prev;
} qnode;

typedef struct{
	qPointer front;
	qPointer rear;
	int count;
}queue;
queue q;

void insert(queue* q,char item[5]){
	qnode *newnode = (qnode*)malloc(sizeof(qnode));
	strcpy(newnode->item,item);
	newnode->next = NULL;
	newnode->prev = NULL;
	q->count++;
	if (q->front == NULL) {
		q->rear = newnode;
		q->front = newnode;
	}
	else{
		newnode->prev = q->rear;
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

int isEmpty(queue *q){
	return q->count == 0;
}


qPointer pop(queue *q,bool state){
	if (!isEmpty(q)){
		if(state){
			qPointer temp = q->front;
			q->front = q->front->next;
			if (q->front){
				q->front->prev = NULL;
			}
			q->count--;
			return temp;
		}
		else{
			qPointer temp = q->rear;
			q->rear = q->rear->prev;
			if (q->rear){
				q->rear->next = NULL;
			}
			q->count--;
			return temp;
		}
	}
	else{
			return NULL;
	}
}
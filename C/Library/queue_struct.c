typedef struct node *nptr;
typedef struct node{
	int x;
	nptr next;
} node;

nptr root = NULL;
nptr tail = NULL;
int len = 0;

void insert(int x) {
	nptr new = (nptr)malloc(sizeof(node));
	new->x = x;
	new->next = NULL;

	if (root == NULL) {
		root = new;
		tail = new;
	}
	else {
		nptr cur = tail;
		cur->next = new;
		tail = new;
	}
	len++;
}

int pop() {
	if (root == NULL) return -1;
	else {
		if (root->next == NULL) tail = NULL;
		nptr cur = root;
		int x = cur->x;
		root = root->next;
		free(cur);
		len--;

		return x;
	}
}

int size() {
	return len;
}

int empty() {
	return (root == NULL);
}

int front() {
	if (root == NULL) return -1;
	else return root->x;
}

int back() {
	if (tail == NULL) return -1;
	else {
		return tail->x;
	}
}
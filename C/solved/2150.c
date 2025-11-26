#include <stdio.h>
#include <stdlib.h>

typedef struct Node* NodePtr;
typedef struct Node {
    int vertex;
    NodePtr next;
} Node;

void topologicalSortRecur(int v, NodePtr* adjList, int* visited, int* stack, int* top) {
    visited[v] = 1;
    NodePtr temp = adjList[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            topologicalSortRecur(temp->vertex, adjList, visited, stack, top);
        }
        temp = temp->next;
    }
    stack[--(*top)] = v;  // top은 포인터이므로 역참조 필요
}

int* topologicalSort(int n, NodePtr* adjList) {
    int* stack = (int*)calloc(n + 1, sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));
    int top = n;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalSortRecur(i, adjList, visited, stack, &top);
        }
    }

    free(visited);
    return stack;
}

void recur(int v, NodePtr* adjList, int* visited, int* result, int idx){
    visited[v] = 1;
    result[v] = idx;

    NodePtr temp = adjList[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            recur(temp->vertex, adjList, visited, result, idx);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    NodePtr* adjList = (NodePtr*)malloc((n + 1) * sizeof(NodePtr));
    NodePtr* adjListRev = (NodePtr*)malloc((n + 1) * sizeof(NodePtr));
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        adjListRev[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        NodePtr newNodeRev = (NodePtr)malloc(sizeof(Node));
        newNodeRev->vertex = u;
        newNodeRev->next = adjListRev[v];
        adjListRev[v] = newNodeRev;
    }

    int* topoOrder = topologicalSort(n, adjListRev);

    int* visited = (int*)calloc(n + 1, sizeof(int));
    int* result = (int*)calloc(n + 1, sizeof(int));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        int v = topoOrder[i];
        if (!visited[v]) {
            recur(v, adjList, visited, result, idx);
            idx++;
        }
    }

    printf("%d\n", idx);
    int* visitedOutput = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        int v = result[i];
        if(visitedOutput[i]) continue;
        visitedOutput[i] = 1;
        printf("%d ", i);
        for (int j = i +1 ; j <= n; j++){
            if(result[j] == v){
                printf("%d ", j);
                visitedOutput[j] = 1;
            }
        }

        printf("-1\n");
    }

    return 0;
}
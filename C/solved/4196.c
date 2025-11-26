#include <stdio.h>
#include <stdlib.h>

typedef struct Node* NodePtr;
typedef struct Node {
    int vertex;
    NodePtr next;
} Node;

void testcase();

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

void dfs(int v, NodePtr* SCCAdj, int* visited, int idx){
    visited[v] = idx;
    NodePtr temp = SCCAdj[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            dfs(temp->vertex, SCCAdj, visited, idx);
        }
        temp = temp->next;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        testcase();
    }
    return 0;
}

void testcase() {
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
    int idx = 1;

    for (int i = 0; i < n; i++) {
        int v = topoOrder[i];
        if (!visited[v]) {
            recur(v, adjList, visited, result, idx);
            idx++;
        }
    }
    idx--;

    NodePtr* SCCAdj = (NodePtr*)malloc((idx+1) * sizeof(NodePtr));
    for (int i = 1; i <= idx; i++) {
        SCCAdj[i] = NULL;
    }

    for (int u = 1; u <= n; u++) {
        NodePtr temp = adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int uSCC = result[u];
            int vSCC = result[v];
            if (uSCC != vSCC) {
                NodePtr newNode = (NodePtr)malloc(sizeof(Node));
                newNode->vertex = vSCC;
                newNode->next = SCCAdj[uSCC];
                SCCAdj[uSCC] = newNode;
            }
            temp = temp->next;
        }
    }

    int* SCCTopOrder = topologicalSort(idx, SCCAdj);
    
    int* visitedSCC = (int*)calloc(idx + 1, sizeof(int));
    int finalIdx = 1;
    for (int i = 0; i < idx; i++) {
        int v = SCCTopOrder[i];
        if (!visitedSCC[v]) {
            dfs(v, SCCAdj, visitedSCC, finalIdx);
            finalIdx++;
        }
    }

    printf("%d\n", finalIdx - 1);
}
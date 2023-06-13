
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct quene {
    int items[MAX_SIZE];
    int front;
    int rear;
} Quene;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int s, int d) {
    Node* newNode = createNode(d);
    newNode->next = graph[s];
    graph[s] = newNode;
    newNode = createNode(s);
    newNode->next = graph[d];
    graph[d] = newNode;
}

Quene* createQuene() {
    Quene* q = (Quene*)malloc(sizeof(Quene));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Quene* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enquene(Quene* q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("Quene is full.\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->items[++q->rear] = value;
    }
}

int dequene(Quene* q) {
    int item;
    if (isEmpty(q)) {
        printf("Quene is empty.\n");
        item = -1;
    } else {
        item = q->items[q->front++];
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void bfs(Node* graph[], int startVertex, int n) {
    int* visited = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    
    Quene* q = createQuene();
    visited[startVertex] = 1;
    enquene(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequene(q);
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enquene(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(q);
    free(visited);
}

int main() {
    Node* graph[6];
    for (int i = 0; i < 6; i++)
        graph[i] = NULL;
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    bfs(graph, 0, 6);

    return 0;
}
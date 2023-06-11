#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
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

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("队列已满.\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("队列为空.\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void bfs(Node* graph[], int startVertex, int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n = 6;
    Node* graph[n];
    for (int i = 0; i < n; i++)
        graph[i] = NULL;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("BFS 算法的结果：\n");
    bfs(graph, 0, n);

    return 0;
}

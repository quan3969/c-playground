
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Quene;

Node* create_node(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void add_edge(Node* graph[], int d, int s) {
    Node* node = create_node(s);
    node->next = graph[d];
    graph[d] = node;

    node = create_node(d);
    node->next = graph[s];
    graph[s] = node;
}

Quene* init_quene() {
    Quene* quene = (Quene*)malloc(sizeof(Quene));
    quene->front = quene->rear = -1;
    return quene;
}

int is_empty(Quene* quene) {
    return (quene->rear == -1) ? 1 : 0;
}

void enquene(Quene* quene, int value) {
    if (quene->rear == MAX_SIZE - 1) {
        return;
    } else {
        if (quene->front == -1)
            quene->front = 0;
        quene->items[++quene->rear] = value;
    }
}

int dequene(Quene* quene) {
    int value;
    if (is_empty(quene))
        value = -1;
    else {
        value = quene->items[quene->front++];
        if (quene->front > quene->rear)
            quene->front = quene->rear = -1;
    }
    return value;
}

void bfs(Node* graph[], int startVertex, int n) {
    unsigned char* visited = (unsigned char*)malloc(sizeof(unsigned char) * n);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    
    Quene* quene = init_quene();
    visited[startVertex] = 1;
    enquene(quene, startVertex);

    while (!is_empty(quene)) {
        int currentVertex = dequene(quene);
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enquene(quene, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(quene);
}

int main() {
    Node* graph[6];
    for (int i = 0; i < 6; i++) {
        graph[i] = NULL;
    }
    
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

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

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

Stack* init_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int is_empty(Stack* stack) {
    return (stack->top == -1) ? 1 : 0;
}

void push(Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->items[stack->top--];
}

void dfs(Node* graph[], int start, int n) {
    unsigned char* visited = (unsigned char*)calloc(n, sizeof(unsigned char));
    
    Stack* stack = init_stack();
    push(stack, start);
    visited[start] = 1;

    while (!is_empty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                push(stack, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(stack);
}

int main() {
    int num_vertices = 6;
    Node* graph[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
    }

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 5);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);

    dfs(graph, 2, num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        Node* temp = graph[i];
        Node* prev;
        while (temp != NULL) {
            prev = temp;
            temp = temp->next;
            free(prev);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int value;
    struct Node* neighbors[MAX_NODES];
} Node;

typedef struct Graph {
    Node* nodes[MAX_NODES];
    int num_nodes;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_nodes = 0;
    return graph;
}

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    return node;
}

void addNode(Graph* graph, Node* node) {
    if (graph->num_nodes < MAX_NODES) {
        graph->nodes[graph->num_nodes++] = node;
    } else {
        printf("Error: graph is\n");
    }
}

void addEdge(Node* node1, Node* node2) {
    int i = 0;
    while (node1->neighbors[i] != NULL && i < MAX_NODES) {
        i++;
    }
    if (i == MAX_NODES) {
        printf("Error: node1 has too many neighbors\n");
        return;
    }
    node1->neighbors[i] = node2;

    i = 0;
    while (node2->neighbors[i] != NULL && i < MAX_NODES) {
        i++;
    }
    if (i == MAX_NODES) {
        printf("Error: node2 has too many neighbors\n");
        return;
    }
    node2->neighbors[i] = node1;
}

int main() {
    // Create a new graph
    Graph* graph = createGraph();

    // Create some nodes
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);

    // Add the nodes to the graph
    addNode(graph, node1);
    addNode(graph, node2);
    addNode(graph, node3);

    // Add some edges
    addEdge(node1, node2);
    addEdge(node1, node3);
    addEdge(node2, node3);

    // Print out the adjacency list of each node
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: ", graph->nodes[i]->value);
        for (int j = 0; j < MAX_NODES; j++) {
            if (graph->nodes[i]->neighbors[j] != NULL) {
                printf("%d ", graph->nodes[i]->neighbors[j]->value);
            }
        }
        printf("\n");
    }

    // Clean up memory
    free(node1);
    free(node2);
    free(node3);
    free(graph);

    return 0;
}

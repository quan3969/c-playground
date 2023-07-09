
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    char* key;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value = hash_value * 31 + key[i];
    }
    return hash_value % TABLE_SIZE;
}

void insert(const char* key) {
    unsigned int index = hash(key);
    Node* new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->next = table[index];
    table[index] = new_node;
}

int find(const char* key) {
    unsigned int index = hash(key);
    Node* current = table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    insert("hello");
    insert("world");
    printf("%d\n", find("hello"));
    printf("%d\n", find("world"));
    printf("%d\n", find("foo"));
    return 0;
}

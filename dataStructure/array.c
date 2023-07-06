#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    size_t front;
    size_t back;
    size_t capacity;
} Array;

void init(Array* a) {
    a->front = 0;
    a->back = 0;
    a->capacity = 10;
    a->items = malloc(a->capacity * sizeof(int));
}

void clear(Array* a) {
    free(a->items);
}

void push_back(Array* a, int item) {
    if (a->back == a->capacity) {
        a->capacity *= 2;
        a->items = realloc(a->items, a->capacity * sizeof(int));
    }
    a->items[a->back++] = item;
}

int pop_back(Array* a) {
    if (a->back == a->front) {
        printf("Array underflow\n");
        return -1;
    }
    return a->items[--a->back];
}

int pop_front(Array* a) {
    if (a->back == a->front) {
        printf("Array underflow\n");
        return -1;
    }
    return a->items[a->front++];
}

int is_empty(Array* a) {
    return (a->front == a->back);
}

Array* duplicate(Array* src) {
    Array* dest;
    dest->front = 0;
    dest->back = src->back - src->front;
    dest->capacity = src->capacity;
    dest->items = realloc(dest->items, dest->capacity);
    for (int i = src->front; i < dest->back; i++) {
        dest->items[i - src->front] = src->items[i];
    }
    return dest;
}

int main() {
    Array a;
    init(&a);

    push_back(&a, 1);
    push_back(&a, 2);
    int item = pop_back(&a);
    printf("%d\n", item);
    item = pop_back(&a);
    printf("%d\n", item);

    push_back(&a, 4);
    push_back(&a, 5);
    item = pop_front(&a);
    printf("%d\n", item);
    item = pop_front(&a);
    printf("%d\n", item);

    clear(&a);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int front;
    int back;
    int capacity;
} Array;

void init(Array* a) {
    a->back = a->front = 0;
    a->capacity = 10;
    a->items = malloc(sizeof(int) * a->capacity);
}

void clear(Array* a) {
    free(a->items);
}

int is_empty(Array* a) {
    return (a->front == a->back);
}

void push_back(Array* a, int item) {
    if (a->back == a->capacity) {
        a->capacity *= 2;
        a->items = realloc(a->items, sizeof(a->capacity));
    }
    a->items[a->back++] = item;
}

int pop_back(Array* a) {
    if (is_empty(a)) {
        printf("Array is empty.\n");
        return -1;
    }
    return a->items[--a->back];
}

int pop_front(Array* a) {
    if (is_empty(a)) {
        printf("Array is empty.\n");
        return -1;
    }
    return a->items[a->front++];
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

    Array* arr;
    init(arr);

    push_back(arr, 34);
    push_back(arr, 90);
    push_back(arr, 109);
    push_back(arr, 23);
    push_back(arr, 678);
    push_back(arr, 954);

    clear(arr);

    return 0;
}
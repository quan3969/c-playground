
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int front;
    int back;
    int capacity;
} Array;

Array* create(int size) {
    Array* arr = malloc(sizeof(Array));
    arr->front = arr->back = 0;
    arr->capacity = size;
    arr->items = malloc(sizeof(int) * arr->capacity);
    return arr;
}

void clear(Array* arr) {
    free(arr->items);
    arr->items = NULL;
    free(arr);
}

int is_empty(Array* arr) {
    return (arr->front == arr->back);
}

void push_back(Array* arr, int item) {
    if (arr->back == arr->capacity) {
        arr->capacity *= 2;
        arr->items = realloc(arr->items, sizeof(int) * arr->capacity);
    }
    arr->items[arr->back++] = item;
}

int pop_back(Array* arr) {
    if (is_empty(arr)) {
        return -1;
    }
    return arr->items[--arr->back];
}

int pop_front(Array* arr) {
    if (is_empty(arr)) {
        return -1;
    }
    return arr->items[arr->front++];
}

void remove_item(Array* arr, int item) {
    int i = arr->front;
    int j = arr->front;
    while (j < arr->back) {
        if (arr->items[j] != item) {
            arr->items[i] = arr->items[j];
            i++;
        }
        j++;
    }
    arr->back = i;
}

Array* duplicate(Array* arr) {
    Array* dest = create(1);
    dest->front = 0;
    dest->back = arr->back - arr->front;
    dest->capacity = arr->capacity;
    dest->items = realloc(dest->items, sizeof(int) * dest->capacity);
    for (int i = arr->front; i < arr->back; i++) {
        dest->items[i - arr->front] = arr->items[i];
    }
    return dest;
}

int main() {

    Array* arr = create(2);

    push_back(arr, 34);
    push_back(arr, 90);
    push_back(arr, 109);
    push_back(arr, 23);
    push_back(arr, 678);
    push_back(arr, 954);

    clear(arr);

    return 0;
}
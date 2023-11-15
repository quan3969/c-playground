
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Item;

typedef struct {
    Item** items;
    int front;
    int back;
    int capa;
} Array;

int is_empty(Array* a) {
    return (a->back == a->front);
}

void push_back(Array* a, Item* m) {
    if (a->back == a->capa) {
        a->capa *= 2;
        a->items = realloc(a->items, (sizeof(Item*) * a->capa));
    }
    a->items[a->back++] = m;
}

Item* pop_back(Array* a) {
    if (is_empty(a)) {
        return NULL;
    }
    return a->items[--a->back];
}

Item* pop_front(Array* a) {
    if (is_empty(a)) {
        return NULL;
    }
    return a->items[a->front++];
}

int main() {

    Array* arr = malloc(sizeof(Array));
    arr->back = arr->front = 0;
    arr->capa = 10;
    arr->items = malloc(sizeof(Item*) * arr->capa);

    Item* m1 = malloc(sizeof(Item));
    m1->row = 1; m1->col = 1;

    Item* m2 = malloc(sizeof(Item));
    m2->row = 2; m2->col = 2;

    Item* m3 = malloc(sizeof(Item));
    m3->row = 3; m3->col = 3;

    push_back(arr, m1);
    push_back(arr, m2);
    push_back(arr, m3);

    Item* temp = pop_back(arr);
    free(temp); // free after use
    temp = pop_front(arr);
    free(temp); // free after use

    int res = is_empty(arr);

    for (int i = arr->front; i < arr->back; i++) {
        free(arr->items[i]); // free remain
    }
    free(arr->items);
    free(arr);

    return 0;
}

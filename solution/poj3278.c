/**
 * 3278. Catch That Cow
 * http://poj.org/problem?id=3278
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int front;
    int back;
    int capa;
} Array;

Array* crete(int capa) {
    Array* a = malloc(sizeof(Array));
    a->back = a->front = 0;
    a->capa = capa;
    a->items = malloc(sizeof(int) * a->capa);
    return a;
}

int is_empty(Array* a) {
    return a->front == a->back;
}

void push_back(Array* a, int item) {
    if (a->back == a->capa) {
        a->capa *= 2;
        a->items = realloc(a->items, sizeof(int) * a->capa);
    }
    a->items[a->back++] = item;
}

int pop_front(Array* a) {
    if (is_empty(a)) {
        return -1;
    }
    return a->items[a->front++];
}

int bfs(int start, int end) {
    Array* q = crete(50);
    Array* t = crete(50);
    push_back(q, start);
    push_back(t, 1);

    while (!is_empty(q)) {
        int cur = pop_front(q);
        int time = pop_front(t);
        if (cur == end) {
            free(q->items);
            free(q);
            free(t->items);
            free(t);
            return time;
        }
        int next_time = time + 1;
        int next = cur + 1;
        if (next >= 0 || next <= 100000) {
            push_back(q, next);
            push_back(t, next_time);
        }
        next = cur - 1;
        if (next >= 0 || next <= 100000) {
            push_back(q, next);
            push_back(t, next_time);
        }
        next = cur * 2;
        if (next >= 0 || next <= 100000) {
            push_back(q, next);
            push_back(t, next_time);
        }
    }
    return -1;
}

int main() {
    int start, end;
    scanf("%d %d", &start, &end);
    int step = bfs(start, end);
    printf("%d", step);
    return 0;
}

/**
 * 46. Permutations
 * https://leetcode.cn/problems/permutations/description/
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** items;
    int back;
    int capacity;
} Array;

typedef struct {
    int* items;
    int back;
    int capacity;
} Track;

void array_push(Array* arr, int* item) {
    if (arr->back == arr->capacity) {
        arr->capacity *= arr->capacity;
        arr->items = realloc(arr->items, sizeof(int*) * arr->capacity);
    }
    arr->items[arr->back++] = item;
}

void backtrack(Array* res, int* nums, Track* track, int* used) {
    if (track->back == track->capacity) {
        int* temp = malloc(sizeof(int) * track->capacity);
        for (int i = 0; i < track->capacity; i++) {
            temp[i] = track->items[i];
        }
        array_push(res, temp);
        return;
    }

    for (int i = 0; i < track->capacity; i++) {
        if (used[i]) {
            continue;
        }
        track->items[track->back++] = nums[i];
        used[i] = 1;
        backtrack(res, nums, track, used);
        track->back--;
        used[i] = 0;
    }
}

int main() {

    int nums[] = { 2, 3, 1 };
    int numsSize = 3;

    Array* res = malloc(sizeof(Array));
    res->back = 0;
    res->capacity = 20;
    res->items = malloc(sizeof(int*) * res->capacity);

    Track* track = malloc(sizeof(Track));
    track->back = 0;
    track->capacity = numsSize;
    track->items = malloc(sizeof(int) * track->capacity);
    
    int* used = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }

    backtrack(res, nums, track, used);

    for (int i = 0; i < res->back; i++) {
        for (int j = 0; j < track->capacity; j++) {
            printf("%d ", res->items[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < res->back; i++) {
        free(res->items[i]);
    }
    free(res->items);
    free(res);
    free(track->items);
    free(track);
    
    return 0;
}

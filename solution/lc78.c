/**
 * 78. Subsets
 * https://leetcode.cn/problems/subsets/
 * 
 */

/*
void backtrack(res, trk, cur) {
    if (cur == end) {
        res.push(trk)
        return
    }
    for (valid n in cur adj) {
        trk.push(cur)
        backtrack(res, trk, n)
        trk.pop
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int back;
    int capacity;
} Track;

typedef struct {
    int** items;
    int* itemSize;
    int back;
    int capacity;
} Array;

void array_push(Array* arr, Track* tra) {
    if (arr->back == arr->capacity) {
        arr->capacity *= 2;
        arr->items = realloc(arr->items, sizeof(int*) * arr->capacity);
        arr->itemSize = realloc(arr->itemSize, sizeof(int) * arr->capacity);
    }
    int* temp = malloc(sizeof(int) * tra->back);
    for (int i = 0; i < tra->back; i++) {
        temp[i] = tra->items[i];
    }
    arr->itemSize[arr->back] = tra->back;
    arr->items[arr->back++] = temp;
}

void track_push(Track* tra, int item) {
    if (tra->back == tra->capacity) {
        tra->capacity *= 2;
        tra->items = realloc(tra->items, sizeof(int) * tra->capacity);
    }
    tra->items[tra->back++] = item;
}

int track_pop(Track* tra) {
    return tra->items[--tra->back];
}

void backtrack(Array* res, Track* track, int* nums, int numsSize, int start) {
    array_push(res, track);

    for (int i = start; i < numsSize; i++) {
        track_push(track, nums[i]);
        backtrack(res, track, nums, numsSize, i + 1);
        track_pop(track);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    Array* res = malloc(sizeof(Array));
    res->back = 0;
    res->capacity = 1;
    res->itemSize = malloc(sizeof(int) * res->capacity);
    res->items = malloc(sizeof(int*) * res->capacity);

    Track* track = malloc(sizeof(Track));
    track->back = 0;
    track->capacity = 1;
    track->items = malloc(sizeof(int) * track->capacity);

    backtrack(res, track, nums, numsSize, 0);

    *returnSize = res->back;
    *returnColumnSizes = malloc(sizeof(int) * res->back);

    int** result = malloc(sizeof(int*) * (res->back + 1));
    for (int i = 0; i < res->back; i++) {
        (*returnColumnSizes)[i] = res->itemSize[i];
        result[i] = malloc(sizeof(int) * res->itemSize[i]);
        for (int j = 0; j < res->itemSize[i]; j++){
            result[i][j] = res->items[i][j];
        }
    }
    result[res->back] = NULL;

    free(res->items);
    free(res->itemSize);
    free(res);
    free(track->items);
    free(track);

    return result;
}

void print_result(int** result, int returnSize, int* returnColumnSizes) {
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main() {

    int nums[] = {1, 2, 3};
    int numsSize = 3;

    int returnSize;
    int *returnColumnSizes;

    int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    print_result(result, returnSize, returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}


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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lo, int hi) {
    int pivot = arr[hi];
    int i = (lo - 1);
    for (int j = lo; j < hi; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[hi]);
    return (i + 1);
}

void quicksort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int pi = partition(arr, lo, hi);
        quicksort(arr, lo, pi - 1);
        quicksort(arr, pi + 1, hi);
    }
}

int quickselect(int arr[], int lo, int hi, int k) {
    if (lo = hi) {
        return arr[lo];
    }
    int pi = partition(arr, lo, hi);
    if (k == pi) {
        return arr[k];
    }
    if (k < pi) {
        return quickselect(arr, lo, pi - 1, k);
    }
    return quickselect(arr, pi + 1, hi, k);
}

void move_zeroes(int arr[], int size) {
    int i = 0;
    int j = 0;
    while (j != size) {
        if (arr[j] != 0) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
}

int binary_search(int arr[], int size, int target) {
    int lo = 0;
    int hi = size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    Array* arr1 = create(5);

    push_back(arr1, 65);
    push_back(arr1, 23);
    push_back(arr1, 54);
    push_back(arr1, 0);
    push_back(arr1, 928);
    push_back(arr1, 0);
    push_back(arr1, 4);

    printf("arr1 = ");
    for (int i = arr1->front; i < arr1->back; i++) {
        printf("%d ", arr1->items[i]);
    }

    Array* arr2 = duplicate(arr1);
    quicksort(arr2->items, arr2->front, arr2->back - 1);

    printf("\narr2 = ");
    for (int i = arr2->front; i < arr2->back; i++) {
        printf("%d ", arr2->items[i]);
    }

    Array* arr3 = duplicate(arr1);
    printf("\narr3 = ");
    for (int i = arr3->front; i < arr3->back; i++) {
        printf("%d ", arr3->items[i]);
    }
    int k = quickselect(arr3->items, arr3->front, arr3->back - 1, 3);

    printf(", 3rd largest num in arr3 = %d", k);

    Array* arr4 = duplicate(arr1);
    move_zeroes(arr4->items, arr4->back - arr4->front);
    printf("\narr4 = ");
    for (int i = arr4->front; i < arr4->back; i++) {
        printf("%d ", arr4->items[i]);
    }


    Array* arr5 = duplicate(arr2);
    int res = binary_search(arr5->items, arr5->back - arr5->front, 23);
    printf("\narr5 = ");
    for (int i = arr5->front; i < arr5->back; i++) {
        printf("%d ", arr5->items[i]);
    }
    printf(", 23 index is %d.", res);

    clear(arr1);
    clear(arr2);
    clear(arr3);
    clear(arr4);
    clear(arr5);

    return 0;
}
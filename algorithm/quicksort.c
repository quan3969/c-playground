
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j = low;
    while (j < high) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int quickselect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pi = partition(arr, low, high);
    if (k == pi) {
        return arr[pi];
    }
    if (k < pi) {
        return quickselect(arr, low, pi - 1, k);
    }
    return quickselect(arr, pi + 1, high, k);
}

int main() {
    int arr1[5] = {45, 23, 12, 25, 66};
    int arr2[5] = {45, 23, 12, 25, 66};
    quicksort(arr1, 0, 4);
    int k = quickselect(arr2, 0, 4, 3);
    
    return 0;
}

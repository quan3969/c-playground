
#include <stdio.h>

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
    int arrToSort[5] = {45, 23, 12, 25, 66};
    int k = quickselect(arrToSort, 0, 4, 3);
    printf("3th smallest element: %d", k);
    return 0;
}

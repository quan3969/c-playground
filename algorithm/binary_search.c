
#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int size, int target) {
    int i = 0;
    int j = size - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] < target) {
            i = mid + 1;
        } else if (arr[mid] > target) {
            j = mid - 1;
        } else if (arr[mid] == target) {
            return mid;
        }
    }
    return -1;
}

int left_bound(int arr[], int size, int target) {
    int i = 0;
    int j = size - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] < target) {
            i = mid + 1;
        } else if (arr[mid] > target) {
            j = mid - 1;
        } else if (arr[mid] == target) {
            j = mid - 1;
        }
    }
    if (i < 0 || i >= size) {
        return -1;
    }
    return arr[i] == target ? i : -1;
}

int right_bound(int arr[], int size, int target) {
    int i = 0;
    int j = size - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] < target) {
            i = mid + 1;
        } else if (arr[mid] > target) {
            j = mid - 1;
        } else if (arr[mid] == target) {
            i = mid + 1;
        }
    }
    if (j < 0 || j >= size) {
        return -1;
    }
    return arr[j] == target ? j : -1;
}

int main() {
    int arr[10] = {1, 3, 5, 5, 5, 5, 5, 5, 7, 9};
    int res = binary_search(arr, 10, 5);
    res = left_bound(arr, 10, 5);
    res = right_bound(arr, 10, 5);
    
    return 0;
}
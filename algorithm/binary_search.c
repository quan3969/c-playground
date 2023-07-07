
#include <stdio.h>

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
    int arr[5] = {1, 3, 5, 7, 9};
    int result = binary_search(arr, 5, 5);
    
    return 0;
}
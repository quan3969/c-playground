
#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        int mid = (i + j) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {1, 3, 5, 7, 9};
    int result = binary_search(arr, 5, 5);
    
    return 0;
}
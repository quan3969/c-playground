
#include <stdio.h>
#include <stdlib.h>

void move_zeroes(int arr[], int size) {
    int i = 0;
    int j = 0;
    while (j < size) {
        if (arr[j] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
}

void remove_item(int arr[], int size, int item) {
    int i = 0;
    int j = 0;
    while (j < size) {
        if (arr[j] != item) {
            arr[i] = arr[j];
            i++;
        }
        j++;
    }
}

void revert_array(int arr[], int size) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int arr1[5] = {0, 23, 0, 2, 123};
    int arr2[5] = {0, 23, 0, 2, 123};
    int arr3[5] = {0, 23, 0, 2, 123};
    move_zeroes(arr1, 5);
    remove_item(arr2, 5, 2);
    revert_array(arr3, 5);

    return 0;
}

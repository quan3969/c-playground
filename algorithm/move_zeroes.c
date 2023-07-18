
#include <stdio.h>
#include <stdlib.h>

void move_zeroes(int arr[], int size) {
    int i = 0, j = 0;
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

int main() {
    int nums[5] = {0, 23, 0, 2, 123};
    move_zeroes(nums, 5);
    return 0;
}

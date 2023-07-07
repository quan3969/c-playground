
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void move_zeroes(int nums[], int size) {
    int i = 0, j = 0;
    while (j < size) {
        if (nums[j] != 0) {
            swap(&nums[i], &nums[j]);
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

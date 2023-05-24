
#include <stdio.h>

void moveZeroes(int nums[], int numsSize)
{
    int i = 0, j = 0;
    while (j < numsSize) {
        if (nums[j] != 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
        }
        j++;
    }
}

int main() {
    int nums[5] = {0, 23, 0, 2, 123};
    moveZeroes(nums, 5);
    return 0;
}

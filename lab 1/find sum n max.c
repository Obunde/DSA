#include <stdio.h>

int calculateSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}

int findMaximum(int nums[], int size) {
    if (size <= 0) {
        printf("Error: Empty array\n");
        // No return statement here
    }

    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input size\n");
        return 1;  // Exit with an error code
    }

    int nums[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Sum of elements: %d\n", calculateSum(nums, n));
    printf("Maximum element: %d\n", findMaximum(nums, n));

    return 0;
}

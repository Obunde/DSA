#include <iostream>
using namespace std;

void array_Rotation(int nums[], int len, int k) {
    k %= len;

    // Reverse the entire array
    int start = 0, end = len - 1;
    while (start < end) {
        int store = nums[start];
        nums[start] = nums[end];
        nums[end] = store;
        start++;
        end--;
    }

    // Reverse the first k elements
    start = 0, end = k - 1;
    while (start < end) {
        int store = nums[start];
        nums[start] = nums[end];
        nums[end] = store;
        start++;
        end--;
    }

    // Reverse the remaining elements
    start = k, end = len - 1;
    while (start < end) {
        int store = nums[start];
        nums[start] = nums[end];
        nums[end] = store;
        start++;
        end--;
    }
}

void get_nums(int len, int nums[]) {
    cout << "Enter elements of your array:" << endl;
    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }
}

int main() {
    int len;
    cout << "Enter the size of the array: ";
    cin >> len;

    int nums[len];  // Static array

    get_nums(len, nums);

    int k;
    cout << "Enter the rotation factor (k): ";
    cin >> k;

    // Perform array rotation
    array_Rotation(nums, len, k);

    // Print the rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << ' ';
    }

    return 0;
}

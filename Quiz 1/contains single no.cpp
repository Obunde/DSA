#include <iostream>

using namespace std;

int nums[7];

void get_nums() {
    cout << "Enter the 7 values of the array:" << endl;
    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
    }
}

int findSingleNumber() {
    for (int i = 0; i < 7; i++) {
        bool hasDuplicate = false;

        for (int j = 0; j < 7; j++) {
            if (i != j && nums[i] == nums[j]) {
                hasDuplicate = true;
                break;
            }
        }

        if (!hasDuplicate) {
            return nums[i];
        }
    }

    // Return some value to indicate that no single number is found
    return -1;
}

int main() {
    get_nums();

    int singleNumber = findSingleNumber();

    if (singleNumber != -1) {
        cout << "The single number is: " << singleNumber << endl;
    } else {
        cout << "No single number found in the array." << endl;
    }

    return 0;
}

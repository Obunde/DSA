#include <iostream>

using namespace std;

int nums[5];
bool state = false;

void get_nums() {
    cout << "Enter the 5 numbers of the array:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }
}

bool hasDuplicates() {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (nums[i] == nums[j]) {
                return true;  // Duplicates found
            }
        }
    }
    return false;  // No duplicates found
}

int removeDuplicates() {
    int newSize = 0;

    for (int i = 0; i < 5; i++) {
        bool isDuplicate = false;
        for (int j = i + 1; j < 5; j++) {
            if (nums[i] == nums[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            nums[newSize++] = nums[i];
        }
    }

    return newSize;
}

int main() {
    get_nums();

    state = hasDuplicates();

    if (state) {
        cout << "Duplicate found: " << nums[0] << endl;  // Assuming nums[0] is printed if a duplicate is found
        int newSize = removeDuplicates();

        // Print the resized array with unique elements
        cout << "Resized array after removing duplicates:" << endl;
        for (int i = 0; i < newSize; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No duplicates found." << endl;
    }

    return 0;
}

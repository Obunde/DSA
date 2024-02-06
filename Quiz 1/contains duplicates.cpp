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

int main() {
    get_nums();

    state = hasDuplicates();

    if (state) {
        cout << "Duplicate found: true " << endl;
    } else {
        cout << "No duplicates found." << endl;
    }

    return 0;
}

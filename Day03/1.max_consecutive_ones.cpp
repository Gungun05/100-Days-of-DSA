/*
Question:
Given a binary array nums, return the maximum number of consecutive 1's
in the array.

Example 1:
Input:
nums = [1 1 0 1 1 1]
Output:
3
Explanation:
The longest sequence of continuous 1's is of length 3.

Example 2:
Input:
nums = [1 0 1 1 0 1]
Output:
2

Constraints:
1 <= nums.length <= 10000
nums[i] is either 0 or 1.
*/

#include <iostream>
using namespace std;

int main() {
    int nums[10000];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter the binary array elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 0;
        }
    }

    cout << "Maximum consecutive ones: " << maxCount << endl;

    return 0;
}

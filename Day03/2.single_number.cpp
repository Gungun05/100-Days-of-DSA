/*
Question:
Given a non-empty array of integers nums, every element appears twice except
for one element. Find and print the element that appears only once.

You must write a solution that runs in O(n) time and uses O(1) extra space.

Example 1:
Input:
nums = [2 2 1]
Output:
1

Example 2:
Input:
nums = [4 1 2 1 2]
Output:
4

Example 3:
Input:
nums = [1]
Output:
1

Constraints:
1 <= nums.length <= 30000
-30000 <= nums[i] <= 30000
All elements appear exactly twice except one.
*/

#include <iostream>
using namespace std;

int main() {
    int nums[30000];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= nums[i];
    }

    cout << "Single number: " << ans << endl;

    return 0;
}

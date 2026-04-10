/*
3379. Transformed Array

Problem Statement:
------------------
You are given an integer array nums that represents a circular array.
Your task is to create a new array result of the same size, following these rules:

For each index i (where 0 <= i < nums.length), perform the following:

1. If nums[i] > 0:
   Move nums[i] steps to the right in the circular array.
   Set result[i] to the value at the landing index.

2. If nums[i] < 0:
   Move abs(nums[i]) steps to the left in the circular array.
   Set result[i] to the value at the landing index.

3. If nums[i] == 0:
   Set result[i] = nums[i].

Note:
- The array is circular.
- Moving beyond the last index wraps to the beginning.
- Moving before index 0 wraps to the end.

Example:
--------
Input: nums = [3, -2, 1, 1]
Output: [1, 1, 1, 3]

Input: nums = [-1, 4, -1]
Output: [-1, -1, 4]

Constraints:
------------
1 <= nums.length <= 100
-100 <= nums[i] <= 100

Approach:
---------
- Use modulo arithmetic to handle circular movement.
- Formula to get correct index:
      newIndex = (i + nums[i] % n + n) % n
- This handles both left and right movement properly.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            } else {
                int newIndex = (i + nums[i] % n + n) % n;
                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};

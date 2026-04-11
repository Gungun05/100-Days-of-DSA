/**
 * LeetCode Problem: 941. Valid Mountain Array
 * Difficulty: Easy
 *
 * Problem Statement:
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 *
 * Recall that arr is a mountain array if and only if:
 *
 * 1. arr.length >= 3
 * 2. There exists some index i with 0 < i < arr.length - 1 such that:
 *    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 *    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 *
 * Examples:
 *
 * Example 1:
 * Input: arr = [2,1]
 * Output: false
 *
 * Example 2:
 * Input: arr = [3,5,5]
 * Output: false
 *
 * Example 3:
 * Input: arr = [0,3,2,1]
 * Output: true
 *
 * Constraints:
 * - 1 <= arr.length <= 10^4
 * - 0 <= arr[i] <= 10^4
 *
 * Approach:
 * - First, climb up the array while elements are strictly increasing.
 * - Check if peak is valid (not first or last index).
 * - Then, go down while elements are strictly decreasing.
 * - If we reach the end, it's a valid mountain array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Length must be at least 3
        if (n < 3) return false;

        int i = 0;

        // Step 2: Walk up (strictly increasing)
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Step 3: Peak cannot be first or last
        if (i == 0 || i == n - 1) return false;

        // Step 4: Walk down (strictly decreasing)
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // Step 5: Check if reached the end
        return i == n - 1;
    }
};

/*
📌 Monotonic Array
🧾 Problem Statement

An array is said to be monotonic if it is either entirely non-increasing or non-decreasing.

An array is monotone increasing if for every i <= j,
nums[i] <= nums[j]
An array is monotone decreasing if for every i <= j,
nums[i] >= nums[j]

Given an integer array nums, return true if the array is monotonic, otherwise return false.
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;
        bool isDecreasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                isDecreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                isIncreasing = false;
            }
        }

        return isIncreasing || isDecreasing;
    }
};

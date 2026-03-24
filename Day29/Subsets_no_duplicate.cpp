//Leetcode Problem 90. Subsets II
/*

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
  
Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]

*/

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {

            // 🔥 Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            solve(i + 1, nums, temp, ans);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 🔥 important
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);
        return ans;
    }
};

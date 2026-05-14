/* 
 Provided with an array of n elements, we have to find every possible subset existing. 
 Problem Statement: Given an integer array nums of unique elements, return all possible subsets (the power set).
 The solution set must not contain duplicate subsets. Return the solution in any order.

 Example 1:
 Input: nums = [1,2,3]
 Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {

public:
    void solve(int i, vector<int> & nums, vector<vector<int>> & ans, vector<int>temp){
        //base case
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        //recursive call for picking the element
        temp.push_back(nums[i]);
        solve(i+1,nums,ans,temp); //note: don't use i++ instead of i+1
        //recursive call for not picking the element (backtracking)
        temp.pop_back();
        solve(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,ans,temp);
        return ans;

    }
};

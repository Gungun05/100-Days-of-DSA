/*
    169. Majority Element

    Given an array nums, return the element that appears more than n/2 times.
    Majority element always exists.

    Example:
    nums = [3,2,3] -> 3
    nums = [2,2,1,1,1,2,2] -> 2
*/

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
    int count = 0;
    int ans = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {
            ans = nums[i];
        }
        if(nums[i] == ans) {
            count++;
        } else {
            count--;
        }
    }

    return ans;
}

int main() {
    vector<int> v1 = {3, 2, 3};
    cout << majorityElement(v1) << endl;

    vector<int> v2 = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(v2) << endl;

    return 0;
}

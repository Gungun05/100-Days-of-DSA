class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int start = 0;
        int end = num.size()-1;
        vector<int> ans;
        while(start<end){
            if(num[start]+num[end]==target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
            else if(num[start]+num[end]<target){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};

//Time Complexity => O(n) As we are traversing the whole array one single time only using two pointers (one would be traversing left half and second one the right half of the array )
//So remember just by using 2 pointers we can reduce the time complexity to half as traversing the whole array using two pointers instead of one

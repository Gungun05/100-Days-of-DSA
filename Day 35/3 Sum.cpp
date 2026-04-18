class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        for (int i=0; i<arr.size(); i++) {
            if (i>0 && arr[i] == arr[i-1]) {
                continue;
            }
            int st=i + 1;
            int end=arr.size()-1;
            
            while (st<end) {
                int sum = arr[i]+arr[st]+arr[end];
                if (sum==0) {
                    result.push_back({arr[i], arr[st], arr[end]});
                    
                    while (st < end && arr[st] == arr[st + 1]) st++;
                    while (st < end && arr[end] == arr[end -1]) end--;
                    
                    st++;
                    end--;
                }
                else if (sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }
        
        return result;
    }
};

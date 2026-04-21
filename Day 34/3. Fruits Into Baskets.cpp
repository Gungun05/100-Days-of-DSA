class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        pair <int, int> count;
        int st=0;
        int maxLen=0;
        for(int end=0; end<fruits.size(); end++) {
            count[fruits[end]]++;
            
            while (count.size() > 2) {
                count[fruits[st]]--;
                if (count[fruits[st]] == 0) {
                    count.erase(fruits[st]);
                }
                
                left++;
            }
            
            // Current window [left, right] has at most 2 fruit types
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count (nums.begin(), nums.end());
        int res = 0 ;
        for(int num : count)
        {
            int length = 1; 
            while(count.find(num + length) != count.end())
            {
                length++;
            }
            res = max(length, res);
        }
        return res; 
        
    }
};

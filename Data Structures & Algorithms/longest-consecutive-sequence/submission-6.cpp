class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin() , nums.end());
        int longest = 0 ;
        for(int num : nums)
        {
            int length = 1 ; 
            if(seen.find(num - 1) == seen.end())
            {
                length = 1;
                while(seen.count(num + length))
                {
                    length++;
                }
            }
            longest = max(longest, length);
        }
        return longest;
        
        
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count (nums.begin() , nums.end());
        int longest = 0; 
        for(int num : count)
        {
            if(count.find(num -1) == count.end())
            {
                int length = 1;
                while(count.find(num + length) != count.end())
                {
                    length++;
                }
                longest = max(longest , length);
            }
        }
        return longest;
        
    }
};

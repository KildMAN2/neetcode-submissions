class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> temp (nums.begin(), nums.end());
        int longest = 0;
        for(int num : nums)
        {
            if(temp.find(num -1) == temp.end());
            {
                int length = 1;
                while(temp.find(num + length) != temp.end())
                {
                    length++;
                }
                longest = max(longest,length);
            }

        }
        return longest;

    }
};
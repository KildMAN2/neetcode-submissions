class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count (nums.begin() , nums.end());
        int res = 0 ; 
        for(int num: nums)
        {
            if(count.find(num - 1) == count.end())
            {
                int length = 1 ;
                while(count.count(num + length))
                {
                    length++;
                }
             res = max(res , length);

            }
        }
        return res;
        
    }
};

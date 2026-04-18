class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int pair = target - nums[i];
            if(seen.find(pair) != seen.end())
            {
                return {seen[pair], i};
            }
            seen[nums[i]] = i ;
        }
        return {};
        
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if(seen.find(temp) != seen.end())
            {
                return {seen[temp], i};
            }
            seen[nums[i]] = i;
        }
        return {};
        
    }
};

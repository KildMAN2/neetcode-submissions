class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> pair;
        for(int i = 0 ; i< nums.size(); i++)
        {
            int x = target - nums[i];
            if(pair.find(x) != pair.end())
            {
                return {pair[x], i};
            }
            pair[nums[i]] = i ;
        }
        return {};
        
    }
};

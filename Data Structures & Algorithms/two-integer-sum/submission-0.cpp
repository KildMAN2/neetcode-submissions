class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int, int> res;
     for(int i = 0; i< nums.size(); i++)
     {
        int x = target - nums[i];
        if(res.find(x) != res.end())
        {
            return {res[x],i};
        }
        res[nums[i]] = i;
     }
     return {};
    }
};

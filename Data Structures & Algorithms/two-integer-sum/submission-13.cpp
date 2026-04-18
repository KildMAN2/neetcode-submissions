class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> count;
        for(int i = 0; i < nums.size() ; i++)
        {
            int temp = target - nums[i];
            if(count.find(temp) != count.end())
            {
                return {count[temp],i};
            }
            count[nums[i]] = i;
        }
        return {};
    }
};

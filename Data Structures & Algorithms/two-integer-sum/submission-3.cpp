class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int > count;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            int x = target - nums[i] ;
            if(count.find(x) != count.end())
            {
                return {count[x] , i};
            }
            count[nums[i]] = i;
        }
        return {};
    }
};

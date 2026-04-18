class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        backtrack(nums , target , subset,0);
        return res;
        
    }
    void backtrack(vector<int>& nums , int target ,vector<int>& subset, int i)
    {
        if(target == 0)
        {
            res.push_back(subset);
            return ;
        }
        if(target < 0 || i >= nums.size())
        {
            return ;
        }
        subset.push_back(nums[i]);
        backtrack(nums, target - nums[i] , subset , i);
        subset.pop_back();
        backtrack(nums,target , subset , i + 1);

    }
};

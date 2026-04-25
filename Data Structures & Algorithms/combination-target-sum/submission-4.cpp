class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        dfs(nums,0,subset,target);
        return res;
        
    }
private: 
    void dfs(const vector<int>& nums , int i ,vector<int> & subset , int target)
    {
        if( target == 0)
        {
            res.push_back(subset);
            return;
        }
        if(i >= nums.size() || target < 0)
        {
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums , i , subset, target - nums[i]);
        subset.pop_back();
        dfs(nums,i + 1,subset,target);
    }
};

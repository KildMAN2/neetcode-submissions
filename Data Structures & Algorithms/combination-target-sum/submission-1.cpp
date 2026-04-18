class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res ; 
        vector<int> subset;
        dfs(nums , 0 , 0 ,target , subset , res);
        return res;
        
    }
private: 
    void dfs(vector<int>&nums , int index , int sum , int target 
                , vector<int> &subset , vector<vector<int>> & res)
    {
        if(sum == target)
        {
            res.push_back(subset);
            return;
        }
        if(sum > target || index >= nums.size())
        {
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums , index  , sum + nums[index] , target , subset , res);
        subset.pop_back();
        dfs(nums , index + 1 , sum , target , subset , res);       
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> subset;
        unordered_set<int> seen;
        sort(candidates.begin() , candidates.end());
        dfs(candidates , 0 , 0 ,target , subset ,res);
        return res;
        
    }
private: 
    void dfs(vector<int>& nums , int index , int sum , int target 
               ,vector<int> &subset, vector<vector<int>>& res)
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
        dfs(nums , index + 1 , sum + nums[index] , target , subset , res);
        subset.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1] )
        {
            index++;
        }
        dfs(nums , index + 1 , sum , target , subset , res);
    }
};

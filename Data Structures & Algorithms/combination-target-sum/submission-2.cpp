class Solution {
public:
    vector<vector<int>> res; 
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        backtracking(nums , 0 , target , subset);
        return res;
        
    }
private:
    void backtracking(vector<int> & nums , int i ,int target , vector<int> &subset )
    {
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }
        if (target < 0 || i >= nums.size())
        {
            return ;
        }
        subset.push_back(nums[i]);
        backtracking(nums , i , target - nums[i] , subset);
        subset.pop_back();
        backtracking(nums , i + 1 , target , subset);
    }
};

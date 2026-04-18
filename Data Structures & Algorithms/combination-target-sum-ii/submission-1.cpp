class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> subset; 
        vector<vector<int>>res;
        dfs(candidates , 0 , 0 ,target , subset , res);
        return res;

        
    }
private:
    void dfs(vector<int>&nums , int index , int sum , int target , 
                vector<int>& subset , vector<vector<int>>& res)
    {
        if(target == sum)
        {
            res.push_back(subset);
            return;
        }
        for(int i = index ; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i - 1]) continue;
            if(sum + nums[i] > target) break;
            subset.push_back(nums[i]);
            dfs(nums , i + 1 , sum + nums[i] , target , subset , res);
            subset.pop_back();
        }
        return;
    }
};

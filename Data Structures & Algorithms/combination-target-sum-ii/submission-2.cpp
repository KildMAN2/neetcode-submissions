class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin() , candidates.end());
        backtracking(candidates , 0 , 0 , target,subset);
        return res;
    }
private: 
    void backtracking(vector<int> & nums , int index , int sum ,int target, vector<int> &subset)
    {
        if(sum == target)
        {
            res.push_back(subset);
            return;
        }

        for(int i = index ; i < nums.size() ; i++)
        {
            if(i > index && nums[i] == nums[i -1]) continue;
            if(sum + nums[i] > target ) break;
            subset.push_back(nums[i]);
            backtracking(nums, i + 1 , sum + nums[i] , target,subset);
            subset.pop_back();
        }
        return;
    }
};

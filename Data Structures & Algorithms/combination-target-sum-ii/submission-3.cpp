class Solution {
public:
    set<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int>subset;
        backtrack(candidates, target, 0 , subset , 0);
        return vector<vector<int>>(res.begin(),res.end());
        
    }
private:
    void backtrack(vector<int>& candidates , int target , int i , vector<int>& subset , int total)
    {
        if(total == target) 
        {
            res.insert(subset);
            return;
        }
        if(total > target || i >= candidates.size())
        {
            return;
        }
        subset.push_back(candidates[i]);
        backtrack(candidates ,target,i +1 , subset ,total + candidates[i]);
        subset.pop_back();
        backtrack(candidates ,target,i +1 , subset ,total);
    }
};

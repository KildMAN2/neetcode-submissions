class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> choosed (nums.size() , false);
        dfs(nums , subset ,choosed);
        return res;
        
    }
private: 
    void dfs(vector<int>& nums, vector<int> subset,vector<bool> choosed)
    {
        if(subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(choosed[i]) continue;
            subset.push_back(nums[i]);
            choosed[i] = true;
            dfs(nums , subset , choosed );
            subset.pop_back();
            choosed[i] = false;

        }
    }
};

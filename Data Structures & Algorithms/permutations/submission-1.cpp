class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> choosed(nums.size() , false);
        backtracking(nums , subset , choosed);
        return res;
        
    }
private:
    void backtracking(vector<int> & nums , vector<int>&subset , vector<bool> choosed)
    {
        if(subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(choosed[i]) continue;
            choosed[i] = true;
            subset.push_back(nums[i]);
            backtracking(nums , subset , choosed);
            choosed[i] = false;
            subset.pop_back();
        }
    }
};

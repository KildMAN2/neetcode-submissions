class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        sort(nums.begin() , nums.end());
        backtracking(nums ,  0 , subset);
        return res;

        
    }
private: 
    void backtracking(vector<int > & nums , int index , vector<int> &subset)
    {
        if(index >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtracking(nums , index + 1 , subset);
        subset.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1])
        {
            index++;
        }
        backtracking(nums , index + 1 , subset);
    }
};

class Solution {
    vector<vector<int>>res; 

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtracking(nums , 0 , subset);
        return res;

        
    }
private: 
    void backtracking(vector<int> & nums , int i , vector<int> & subset)
    {
        if(i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtracking(nums,i+1,subset);
        subset.pop_back();
        backtracking(nums,i+1,subset);
    }

};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> robs(n+1);
        robs[0] = nums[0];
        robs[1] = max(nums[0],nums[1]);
        for(int i = 2 ; i< nums.size();i++)
        {
            robs[i] = max(robs[i-1],robs[i-2] + nums[i]);
        }
        return robs[n - 1];
    }
};

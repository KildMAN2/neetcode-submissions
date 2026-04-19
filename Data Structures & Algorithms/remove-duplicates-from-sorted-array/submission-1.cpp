class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int prev = nums[0] ; 
        int countU = 1;

        for(int i = 0; i <  nums.size() ; i++)
        {
            if(nums[i] == prev)
            {
                continue;
            }
            nums[countU++] = nums[i];
            prev = nums[i];
        }
        return countU;
        
    }
};
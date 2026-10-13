class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =0 ; 
        for(int r = 0; r < nums.size(); r++)
        {
            if(nums[r] != val)
            {
                nums[k++] = nums[r];
            }
        }
        return k;
        
    }
};
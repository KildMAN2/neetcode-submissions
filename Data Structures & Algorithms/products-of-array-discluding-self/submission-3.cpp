class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res ;
        int temp_all = 1;
        int index_zero = -1;
        int count =0 ;
        for(int i =0 ; i< nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                temp_all *= nums[i];
            }
            else
            {
                count ++;
            }
        }
        if(count > 1)
        {
            return vector<int>(nums.size(),0);
        }
        if(count != 1) {
             for (int i = 0 ; i< nums.size(); i++ ){
                int target = temp_all  / nums[i];
                 res.push_back(target);
            }  
        }
        else
        {
            for(int num : nums)
            {
                if(num == 0)
                {
                    res.push_back(temp_all);
                }
                else
                {
                    res.push_back(0);
                }
            }
        }
        return res;

    }
};

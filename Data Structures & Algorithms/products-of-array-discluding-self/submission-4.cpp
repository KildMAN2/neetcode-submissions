class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int temp_all = 1; 
        int count_zero=0;
        for(int num : nums)
        {
            if(num != 0)
            {
                temp_all *= num;
            }
            else
            {
                count_zero++;
            }
        }
        if(count_zero > 1)
        {
            return vector<int>  (nums.size(),0);
        }
        for(int num : nums)
        {
            if(num == 0)
            {
                res.push_back(temp_all);
            }
            else
            {
                if(count_zero == 0)
                {
                   int x = temp_all / num;
                   res.push_back(x);
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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1 ; 
        int countZero = 0 ; 
        for(int num : nums)
        {
            if(num == 0)
            {
                countZero++;
            }
            else
            {
                mul *= num;
            }
        }
        if(countZero > 1)
        {
            return vector<int>(nums.size());
        }
        vector<int> res;
        for(int num : nums)
        {
            if(countZero == 1)
            {
                if(num == 0)
                {
                    res.push_back(mul);
                }
                else
                {
                    res.push_back(0);
                }
            }
            else
            {
                res.push_back(mul / num);
            }
        }
        return res;
    }
};

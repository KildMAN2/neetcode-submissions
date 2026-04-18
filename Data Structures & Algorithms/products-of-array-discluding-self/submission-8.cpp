class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tempAll = 1;
        int countZeros = 0;
        for(int num : nums)
        {
            if(num == 0)
            {
                countZeros++;
            }
            else
            {
                tempAll *= num;
            }
        }
        if(countZeros >=2)
        {
            return vector<int> (nums.size(),0);
        }
        vector<int> res;
        for(int num : nums)
        {
            if(countZeros == 1)
            {
                if(num == 0)
                {
                    res.push_back(tempAll);
                }
                else
                {
                    res.push_back(0);
                }
            }
            else
            {
            res.push_back((tempAll)/ num);
            }
        }
        return res;


    }
};

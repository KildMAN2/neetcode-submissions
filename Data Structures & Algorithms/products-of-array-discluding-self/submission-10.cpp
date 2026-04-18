class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tempall = 1 ; 
        int countzero = 0 ; 
        for(int num : nums)
        {
            if(num)
            {
                tempall *= num;
            }
            else
            {
                countzero++;
            }
        }
        if(countzero > 1)
        {
            return vector<int> (nums.size() , 0);
        }
        vector<int> res;
        for( int num: nums)
        {
            if(countzero == 1)
            {
                if(num)
                {
                    res.push_back(0);
                }
                else
                {
                    res.push_back(tempall);
                }
            }
            else
            {
                res.push_back(tempall / num);
            }
        }
        return res;

    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> result  ; 
       int temp_all = 1;
       int count_zero = 0 ;
       for(int num :nums)
       {
            if(num !=0)
            {
                temp_all *= num;
            }
            else
            {
                count_zero ++;
            }
       }
       if(count_zero > 1)
       {
        return vector<int> (nums.size(),0);
       }
       for(int num : nums)
       {
            if(count_zero != 1)
            {
                int temp = temp_all / num;
                result.push_back(temp);
            }
            else
            {
                if(num == 0)
                {
                    result.push_back(temp_all);
                }
                else 
                {
                    result.push_back(0);
                }

            }
       }
       return result;

    }
};

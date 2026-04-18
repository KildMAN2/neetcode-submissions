class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> seen;
        int i=0;
        for(int num : nums)
        {
            int x = target - num;
            if(seen.find(x)!= seen.end())
            {
                return {seen[x],i};
            }
           seen[num]= i;
            i++;
        }
        return {};

    }
};

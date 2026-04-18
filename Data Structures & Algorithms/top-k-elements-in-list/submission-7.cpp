class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int > count ;
        for (int num :nums)
        {
            count[num]++;
        }
        vector<vector<int>>buckets (nums.size() + 1);
        for(const auto & pair : count)
        {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> result;
        for(int i = nums.size(); i >= 0 ; i-- )
        {
            for(int num : buckets[i])
            {
                if(result.size() == k)
                {
                    return result;
                }
                result.push_back(num);
            }
        }
        return result;
        
    }
};

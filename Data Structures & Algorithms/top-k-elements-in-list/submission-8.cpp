class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int ,int> count;
        vector<vector<int>> buckets (nums.size() +1);
        for(int n : nums)
        {
            count[n]++;
        }
        for(const auto & pair : count)
        {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for(int i = buckets.size() - 1 ; i>= 0 ; i--)
        {
            for(int num : buckets[i])
            {
                res.push_back(num);
                if(res.size() == k)
                {
                    return res;
                }
            }

        }
        return res;
        
    }
};

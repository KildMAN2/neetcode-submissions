class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> count ;
        vector<vector<int>> buckets(nums.size() + 1);
        for(int num : nums)
        {
            count[num]++;
        }
        for(const auto & c : count)
        {
            buckets[c.second].push_back(c.first);
        }
        vector<int> result;
        for(int i = buckets.size() - 1; i > 0; i--)
        {
            for(int num : buckets[i])
            {
                result.push_back(num);
                if(result.size() == k)
                {
                    return result;
                }

            }
        }
        return result;


    }
};

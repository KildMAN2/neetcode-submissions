class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> buckets (nums.size() +1);
        for(int num :nums)
        {
            count[num]++;
        }
        for(const auto& pair  : count)
        {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> result;
        for(int i = buckets.size() -1 ; i>=0; i--)
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

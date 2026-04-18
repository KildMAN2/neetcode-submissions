class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> pairs;
        vector<vector<int>> buckets(nums.size()+1);
        for(int n :nums)
        {
            pairs[n]++;
        }
        for(auto & pair : pairs)
        {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for(int i = buckets.size() - 1 ; i>= 0 ; i--)
        {
            for(int num : buckets[i])
            {
                if(res.size() == k)
                {
                    return res;
                }
                res.push_back(num);
            }
        }
        return res;
        
    }
};

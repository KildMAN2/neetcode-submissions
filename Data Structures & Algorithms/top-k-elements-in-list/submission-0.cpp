class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        unordered_map<int,vector<int>> frequents(nums.size() + 1);
        for(int num : nums)
        {
            count[num]++;
        }
        for(auto & p : count)
        {
            frequents[p.second].push_back(p.first);
        }
        vector<int> res;
        for(int i = nums.size() ; i >= 0 ; i--)
        {
            for(int num : frequents[i])
            {
                if(res.size() == k) return res;
                res.push_back(num);
            }
        }
        return res;
        
    }
};

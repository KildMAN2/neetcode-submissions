class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> pairs;
        for(const auto & s : strs)
        {
            vector<int> hist (26,0);
            for(char c : s)
            {
                hist[c - 'a']++;
            }
            string key = to_string(hist[0]);
            for(int i = 1 ; i < 26 ; i++)
            {
                key += ',' + to_string(hist[i]);
            }
            pairs[key].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto & pair : pairs)
        {
            res.push_back(pair.second);
        }
        return res;
        
    }
};

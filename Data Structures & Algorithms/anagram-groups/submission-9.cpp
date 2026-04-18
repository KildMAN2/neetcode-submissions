class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> pairs;
        vector<vector<string>> res;
        for(const string & s : strs)
        {
            vector<int> count (26,0);
            for(char c : s)
            {
                count[c -'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1 ; i<26 ; i++)
            {
                key += ',' + to_string(count[i]);
            }
            pairs[key].push_back(s);
        }
        for(const auto & pair : pairs)
        {
            res.push_back(pair.second);
        }
        return res;
        
    }
};

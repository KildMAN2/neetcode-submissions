class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Smap;
        for(const string & s : strs)
        {
            vector<int> hist (26,0);
            for(const char c : s)
            {
                hist[c - 'a']++;
            }
            string key = to_string(hist[0]);
            for(int i = 1 ; i<26; i++)
            {
                key += ',' + to_string(hist[i]);
            }
            Smap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto & pair : Smap )
        {
            result.push_back(pair.second);
        }
        return result;
        
    }
};

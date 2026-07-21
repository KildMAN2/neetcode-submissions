class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>> groups;
        for(const string & s : strs)
        {
            vector<int> histogram (26,0);
            for(char c : s)
            {
                histogram[c -'a']++;
            }
            string key = to_string(histogram[0]);
            for(int i = 1 ; i < 26 ; i++)
            {
                key += ',' + to_string(histogram[i]);
            }
            groups[key].push_back(s);
        }
        for(auto & p : groups)
        {
            res.push_back(p.second);
        }
        return res;
        
    }
};

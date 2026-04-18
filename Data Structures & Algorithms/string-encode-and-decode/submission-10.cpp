class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string s : strs)
        {
            res += to_string(s.length()) + "@" + s;
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res; 
        int l = 0 ; 
        while(l < s.length())
        {
            int r = l ; 
            while(s[r]  != '@')
            {
                r++;
            }
            int length = stoi(s.substr(l , r - l ));
            l = r + 1;
            r = l + length;
            res.push_back(s.substr(l,length));
            l = r;
        }
        return res;

    }
};

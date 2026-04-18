class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())
        {
            return "";
        }
        unordered_map<char,int> window , countT ;
        for(char c : t)
        {
            countT[c]++;
        }
        pair<int,int> pair;
        int reslen = INT_MAX;
        int have = 0 ;
        int need = countT.size();
        int l = 0;
        for(int r = 0 ; r < s.length(); r++)
        {
            char c = s[r];
            window[c]++;
            if(countT.count(c) && window[c] == countT[c])
            {
                have++;
            }
            while(have == need)
            {
                if(r - l + 1 < reslen)
                {
                    reslen = r - l + 1;
                    pair = {l ,r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
                {
                    have--;
                }
                l++;
            }
        }
        return reslen == INT_MAX ? "" : s.substr(pair.first , reslen);

        
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map <char , int> countT , window;
        for(char c : t)
        {
            countT[c]++;
        }
        int have = 0 , need = countT.size();
        pair<int,int> pair = {-1,-1};
        int minReslen = INT_MAX;
        int l = 0 ;
        for(int r = 0 ; r< s.length() ; r++)
        {
            char c = s[r];
            window[c]++;
            if(countT.count(c) && countT[c] == window[c])
            {
                have++;
            }
            while(have == need)
            {
                if(r - l + 1 < minReslen)
                {
                    minReslen = r - l + 1;
                    pair = {l ,r};
                }
                window[s[l]]-- ;
                if( countT.count(s[l]) && countT[s[l]] > window[s[l]] )
                {
                    have--;
                }
                l++;
            }
        }
        return (minReslen == INT_MAX) ? "" : s.substr(pair.first,minReslen);
    }
};

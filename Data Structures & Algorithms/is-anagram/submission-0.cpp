class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> hist(26,0) ;
        for(int i = 0; i< s.length();i++)
        {
            hist[s[i] - 'a']++;
            hist[t[i] - 'a']--;
        }
        for(int i = 0 ; i < 26; i++)
        {
            if(hist[i] !=0) return false;
        }
        return true;
        
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        vector<int> histogram (26,0);
        for(int i = 0; i<s.length(); i++)
        {
            histogram[s[i] - 'a'] ++;
            histogram[t[i] - 'a']--;
        }
        for(int i =0; i<26 ; i++)
        {
            if(histogram[i])
            {
                return false;
            }
        }
        return true;
    }
};

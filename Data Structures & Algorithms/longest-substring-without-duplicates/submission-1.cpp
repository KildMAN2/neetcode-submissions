class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> temp;
        int longest = 0, res=0;
        for(int r = 0 ; r<s.length(); r++)
        {
            if(temp.find(s[r])  != temp.end())
            {
                longest = max(longest , temp[s[r]] +1);
            }
            temp[s[r]] = r;
            res = max(res,r - longest +1);
        }
        return res;

    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> seen;
        int res = 0 ;
        int l = 0; 
        for(int r = 0 ; r < s.length(); r++)
        {
            while(seen.find(s[r]) != seen.end())
            {
                seen.erase(s[l]);
                l++;
            }
            res = max(res , r - l + 1);
            seen[s[r]]++;
        }
        return res;
        
    }
};

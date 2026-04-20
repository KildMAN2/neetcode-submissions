class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen;
        int l = 0 ; 
        int maxLength = 0;
        for(int r = 0 ;r < s.length() ; r++)
        {
            seen[s[r]]++;
            while(seen[s[r]] > 1)
            {
                seen[s[l]]--;
                l++;
            }
            maxLength = max(maxLength , r - l + 1);
        }
        return maxLength;
        
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0 ; 
        int left = 0 ; 
        unordered_set<char> seen; 
        for(int r = 0 ; r < s.length() ; r++)
        {
            while(seen.find(s[r]) != seen.end())
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[r]);
            maxLength = max(maxLength, r - left + 1);
        }
        return maxLength;
        
    }
};

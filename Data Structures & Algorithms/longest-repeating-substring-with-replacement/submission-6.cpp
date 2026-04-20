class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char ,int> seen;
        int l = 0 ; 
        int maxLength = 0; 
        int maxF= 0;
        for(int r = 0; r < s.length() ; r++)
        {
            seen[s[r]]++;
            maxF = max(maxF , seen[s[r]]);
            while((r - l +1) - maxF > k )
            {
                seen[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
        
    }
};

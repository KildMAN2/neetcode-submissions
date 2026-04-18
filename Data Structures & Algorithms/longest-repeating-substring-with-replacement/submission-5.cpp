class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char , int> window;
        int maxLength = 0 ; 
        int l = 0 ; 
        int maxF = 0 ; 
        for(int r = 0 ; r < s.length(); r++)
        {
            window[s[r]]++;
            maxF = max(maxF, window[s[r]]);
            while((r - l + 1) - maxF > k )
            {
                window[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l +1);
        }
        return maxLength;
        
    }
};

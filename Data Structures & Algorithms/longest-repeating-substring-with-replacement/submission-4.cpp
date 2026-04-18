class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> window;
        int l = 0 ;
        int maxLength = 0 ;
        int maxSameLetter =0;
        for(int r = 0 ; r < s.length() ; r++)
        {
            window[s[r]]++;
            maxSameLetter = max(maxSameLetter , window[s[r]]);
            while((r - l + 1) - maxSameLetter > k)
            {
                window[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
        
    }
};

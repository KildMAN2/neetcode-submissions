class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0 ;
        int l = 0 ; 
        unordered_map<char , int > count;
        int maxf = 0 ;
        for(int r = 0 ; r< s.length() ; r++ )
        {
            maxf = max(maxf , count[s[r]] + 1);
            while((r - l + 1)  -maxf  > k)
            {
                count[s[l]]--;
                l++;
            }
            count[s[r]]++;
            res = max(res , r - l + 1);
            
        }
        return res;
        
    }
};

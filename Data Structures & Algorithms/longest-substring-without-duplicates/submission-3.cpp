class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ;
        int res = 0 ; 
        unordered_map<char,int> box;
        for(int r = 0 ; r < s.length() ; r++)
        {
            if(box.find(s[r]) != box.end())
            {
                l = max(l , box[s[r]]  + 1);
            }
            box[s[r]] = r;
            res = max(res , r - l + 1);
        }
        return res;
        
    }
};

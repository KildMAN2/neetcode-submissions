class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0 ;
        for(int i = 0 ; i + 1 < s.length() ; i++)
        {
            int diff = abs(s[i] - s[i+1]);
            sum += diff;
        }
        return sum;
        
    }
};
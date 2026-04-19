class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res ;
        int l1 = 0 ; 
        int l2 = 0 ; 
        while(l1 < word1.length() && l2 < word2.length())
        {
            if(l1 <= l2)
            {
                res += word1[l1];
                l1++;
            }
            else
            {
                res+= word2[l2];
                l2++;
            }
        }
        if(l1 < word1.length())
        {
            res += word1.substr(l1,word1.length());
        }
        else
        {
            res += word2.substr(l2,word2.length());
        }
        return res;
    }
};
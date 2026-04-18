class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
        {
            return false;
        }
        vector<int> countS1 (26,0);
        vector<int> countS2 (26,0);
        for(int i = 0 ; i<s1.length() ; i++)
        {
            countS1[s1[i] - 'a']++;
            countS2 [s2[i] - 'a'] ++;
        }
        int matches = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(countS1[i] == countS2[i])
            {
                matches++;
            }
        }
        int l = 0;
        for(int i = s1.length(); i<s2.length() ; i++)
        {
            if(matches == 26)
            {
                return true;
            }
            int index = s2[i] - 'a';
            countS2[index]++;
            if(countS1 [index]  == countS2[index])
            {
                matches++;
            }
            else if (countS1 [index] + 1  == countS2[index])
            {
                matches --;
            }
            index = s2[l] - 'a';
            countS2[index]--;
            if(countS1 [index]  == countS2[index])
            {
                matches++;
            }
            else if (countS1 [index] - 1  == countS2[index])
            {
                matches --;
            }
            l++;
        }
        return matches == 26;
        
    }
};

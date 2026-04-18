class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> countT(26,0), window (26,0);
        int matches = 0 ;
        for(int i = 0 ; i< s1.length() ; i++)
        {
            countT[s1[i] - 'a']++;
            window[s2[i]- 'a']++;
        }
        for(int i =0 ; i < 26 ;i++)
        {
            if(window[i] == countT[i] )
            {
                matches++;
            }
        }
        int l = 0;
        for(int r = s1.length() ; r<s2.length(); r++)
        {
            if(matches == 26)
            {
                return true;
            }
            int index = s2[r] - 'a';
            window[index]++;
            if(window[index] - 1 == countT[index])
            {
                matches--;
            }
            else if(window[index] == countT[index])
            {
                matches++;
            }
            index = s2[l] - 'a';
            window[index]--;
            if(window[index] + 1 == countT[index])
            {
                matches --;
            }
            else if( window[index] == countT[index])
            {
                matches++;
            }
            l++;
        }
        return matches == 26 ;
    }
};

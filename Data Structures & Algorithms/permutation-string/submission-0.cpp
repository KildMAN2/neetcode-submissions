class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
        {
            return false;
        }
        vector<int>S1count (26 ,0);
        vector<int>S2count (26 ,0);
        for(int i =0; i < s1.length() ; i++)
        {   
            S1count[s1[i] - 'a']++;
            S2count[s2[i] - 'a']++;
        }
        int matches = 0 ;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(S1count[i] == S2count[i])
            {
                matches++;
            }
        }
        int l = 0 ; 
        for(int r = s1.length(); r < s2.length(); r++)
        {
            if(matches == 26)
            {
                return true;
            }
            int index = s2[r] - 'a';
            S2count[index]++;
            if(S1count[index] + 1 == S2count[index])
            {
                matches--;
            }
            else if(S1count[index] == S2count[index])
            {
                matches++;
            }
            index = s2[l] - 'a';
            S2count[index]--;
            if(S1count[index] == S2count[index])
            {
                matches++;
            }
            else if (S1count[index] - 1 == S2count[index])
            {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};

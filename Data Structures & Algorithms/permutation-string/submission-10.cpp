class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
        {
            return false;
        }
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);
        for(int i = 0 ; i < s1.length(); i++)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        int contains = 0 ;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(s1Count[i] == s2Count[i])
            {
                contains++;
            }
        }
        int l = 0 ; 
        for(int r = s1.length(); r < s2.length(); r++)
        {
            if(contains == 26)
            {
                return true;
            }
            int index = s2[r]- 'a';
            s2Count[index]++;
            if(s2Count[index] == s1Count[index] + 1)
            {
                contains--;
            }
            else if(s2Count[index] == s1Count[index])
            {
                contains++;
            }
            index = s2[l] - 'a';
            l++;
            s2Count[index]--;
            if(s2Count[index] + 1 == s1Count[index])
            {
                contains--;
            }
            else if(s2Count[index] == s1Count[index])
            {
                contains++;
            }
        }
        return contains == 26;
        
    }
};

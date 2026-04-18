class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 ; 
        int right = s.length() - 1;
        while ( left < right)
        {
            while( left < right && !isLetterNumber(s[left]))
            {
                left++;
            }
            while( left < right && !isLetterNumber(s[right]))
            {
                right--;
            }
            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
        
    }
    bool isLetterNumber ( char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
                (c >= 'A' && c <= 'Z');
    }
};

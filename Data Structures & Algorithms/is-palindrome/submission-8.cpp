class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 , right = s.length() -1;
        while (left < right)
        {
            while (left < right && !checkIsAlphaNum(s[left]))
            {
                left++;
            }
            while (left < right && !checkIsAlphaNum(s[right]))
            {
                right--;
            }
            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;

        }
        return true;
        
        
    }
    bool checkIsAlphaNum(char c)
    {
        return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
                || ('0' <= c && c <= '9'));
    }
};

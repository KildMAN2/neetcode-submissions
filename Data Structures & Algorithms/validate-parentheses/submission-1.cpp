class Solution {
public:
    bool isValid(string s) {
        unordered_map<char , char> isCloseToOpen = 
        {
            {')' ,'('} , {']','['} ,{'}','{'}
        };
        stack<char> stack;
        for(char c : s)
        {
            if(isCloseToOpen.count(c))
            {
                if(!stack.empty() && isCloseToOpen[c] == stack.top())
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

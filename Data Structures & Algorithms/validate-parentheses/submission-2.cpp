class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char > closeToopen = {{')','('} , {']','['} , {'}','{'}};
        stack<char> stack;
        for(char c : s)
        {
            if(closeToopen.count(c))
            {
                if(!stack.empty() && stack.top() == closeToopen[c])
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

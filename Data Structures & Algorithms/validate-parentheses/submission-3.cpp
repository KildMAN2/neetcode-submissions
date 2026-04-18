class Solution {
public:
    bool isValid(string s) {
        unordered_map<char , char> closeToOpen = {{')' , '('} 
                                               , {']','['}
                                               ,  {'}' , '{'}};
        stack<char> stack;
        for(char c  : s)
        {
            if(closeToOpen.count(c))
            {
                if(!stack.empty() && stack.top() == closeToOpen[c])
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

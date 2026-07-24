class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> closeToOpen ={{')' , '('} ,{']' ,'['}  , {'}','{'}};
        stack<char> st;
        for(char c : s)
        {
            if(closeToOpen.count(c))
            {
                if(!st.empty() && closeToOpen[c] == st.top())
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
        
    }
};

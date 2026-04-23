class Solution {
public:
    string simplifyPath(string path) {
       vector<string> stack;
       string cur ;
        for(char c : path + "/")
        {
            if(c == '/')
            {
                if(cur == "..")
                {
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }
                }
                else if(!cur.empty() && cur != ".")
                {
                    stack.push_back(cur);
                }
                cur.clear();
            }
            else
            {
                cur += c;
            }
        }
        string res = "/";
        for(int i = 0 ; i < stack.size(); i++)
        {
            if(i > 0 ) res += "/";
            res += stack[i];
        }
        return res;
    }
};
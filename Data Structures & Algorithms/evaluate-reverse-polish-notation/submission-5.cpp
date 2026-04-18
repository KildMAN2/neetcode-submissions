class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for(const string & s : tokens)
        {
            if(s == "+")
            {
                int b = res.top(); res.pop();
                int a = res.top(); res.pop();
                res.push((a + b));
            }
            else if( s == "-")
            {
                int b = res.top(); res.pop();
                int a = res.top(); res.pop();
                res.push((a - b));
            }
            else if( s == "*")
            {
                int b = res.top(); res.pop();
                int a = res.top(); res.pop();
                res.push((a * b));
            }
            else if(s == "/")
            {
                int b = res.top(); res.pop();
                int a = res.top(); res.pop();
                res.push((a/ b));
            }
            else
            {
                res.push(stoi(s));
            }
        }
        return res.top();
        
    }
};

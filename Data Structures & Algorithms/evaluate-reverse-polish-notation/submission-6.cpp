class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack ; 
        for(string token : tokens)
        {
            if(token == "+")
            {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a + b );
            }
            else if (token == "-")
            {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a - b );
            }
            else if (token == "*")
            {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a * b );
            }
            else if (token == "/")
            {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a / b );
            }
            else
            {
             stack.push(stoi(token));
            }

        }
        return stack.top();
        
    }
};

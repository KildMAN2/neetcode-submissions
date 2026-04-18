class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(string s : tokens)
        {
            if(s == "+")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(a + b);
            }
            else if(s == "-")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(b -a);
            }
            else if (s == "*")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(a * b);
            }
            else if(s == "/")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(b /a);
            }
            else
            {
                numbers.push(stoi(s));
            }

        }
        return numbers.top();
        
    }
};

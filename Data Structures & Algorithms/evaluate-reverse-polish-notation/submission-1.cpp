class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> numbers;
        for(const auto & c : tokens)
        {
            if(c == "+")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(a + b);
            }
            else if ( c == "-")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(b - a);
            } else if ( c == "*")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(a * b);
            } else if ( c == "/")
            {
                int a = numbers.top(); numbers.pop();
                int b = numbers.top(); numbers.pop();
                numbers.push(b /a);
            }
            else
            {
                numbers.push(stoi(c));
            }
        }
        return numbers.top();
        
    }
};

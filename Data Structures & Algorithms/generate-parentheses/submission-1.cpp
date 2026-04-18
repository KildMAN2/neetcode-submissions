class Solution {
public:
    void backtrack(int closedN , int openN , int n ,vector<string>& res, string& stack)
    {
        if(openN == n && closedN == openN)
        {
            res.push_back(stack);
            return;
        }
        if(openN < n)
        {
            stack += '(';
            backtrack(closedN , openN + 1 , n ,res ,stack);
            stack.pop_back();
        }
        if(closedN < openN)
        {
            stack += ')';
            backtrack(closedN + 1 , openN , n ,res ,stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;

        
    }
};

class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string stack;
        dfs(n , 0 ,0 , stack);
        return res;
        
    }
private: 
    void dfs(int n , int closedN , int openN , string& stack)
    {
        if(openN == closedN && closedN == n)
        {
            res.push_back(stack);
        }
        if(openN < n)
        {
            stack += '(';
            dfs(n , closedN , openN + 1 , stack);
            stack.pop_back();
        }
        if(closedN < openN)
        {
            stack += ')';
            dfs(n , closedN + 1 , openN , stack);
            stack.pop_back();
        }
    }

};

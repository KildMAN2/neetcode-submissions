class Solution {
public:
vector<string> res;
    vector<string> generateParenthesis(int n) {
        string stack ;
        backtrack(n , 0 , 0 ,stack);
        return res;
        
    }
private:
    void backtrack(int n , int closedN, int openN , string & stack)
    {
        if(closedN == openN && openN ==n)
        {
            res.push_back(stack);
            return;
        }
        if(openN < n)
        {
            stack += "(";
            backtrack(n , closedN, openN + 1 , stack);
            stack.pop_back();
        }
        if(closedN < openN)
        {
            stack += ")";
            backtrack(n , closedN + 1, openN , stack);
            stack.pop_back();
        }
    }
};

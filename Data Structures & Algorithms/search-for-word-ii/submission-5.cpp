class Solution {
public:
int ROWS , COLS;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        vector <string> res;
        for(string word : words)
        {
            bool found = false;
            for(int r = 0  ; r< ROWS && !found ; r++ )
            {
                for(int c = 0 ; c < COLS && !found ; c++ )
                {
                    if(board[r][c] != word[0]) continue;
                    if(dfs(board,r,c,0,word))
                    {
                        res.push_back(word);
                        found = true;
                        break;
                    }
                }
            }
        }
        return res;
        
    }
private:
    bool dfs(vector<vector<char>>& board , int r , int c , int i , string &word)
    {
        if( i == word.length()) return true; 
        if(  c < 0 || r < 0 || c >= COLS  || r >= ROWS || board[r][c] != word[i])
        {
            return false;
        }
        board[r][c] = '*';
        bool res = dfs(board , r + 1 ,c , i + 1 , word ) ||
                   dfs(board , r - 1 ,c , i + 1 , word ) ||
                   dfs(board , r,c + 1 , i + 1 , word ) ||
                   dfs(board , r   ,c - 1 , i + 1 , word ) ;
        board[r][c] = word[i];
        return res;
    }
};

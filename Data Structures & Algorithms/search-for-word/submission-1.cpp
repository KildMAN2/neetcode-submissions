class Solution {
public:
int ROWS, COLS;
vector<vector<bool>> visited ;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>> (ROWS , vector<bool>(COLS,false));
        for(int r = 0 ; r < ROWS; r++)
        {
            for(int c = 0 ; c < COLS; c++)
            {
                if(dfs(board, r ,c ,0 , word))
                {
                    return true;
                }
            }
        }
        return false;
        
        
    }
private:
    bool dfs(vector<vector<char>>& board ,int r , int c ,int i , string& word)
    {
        if(i == word.size())
        {
            return true;
        }
        if(r < 0 || c < 0 || c >= COLS || r >= ROWS || visited[r][c] || board[r][c] != word[i])
        {
            return false;
        }
        visited[r][c] = true;
        bool res = dfs(board, r + 1 , c , i + 1 , word) ||
                   dfs(board, r - 1 , c , i + 1 , word) ||
                   dfs(board, r , c + 1 , i + 1 , word) ||
                   dfs(board, r , c - 1 , i + 1 , word);
        visited[r][c] = false;
        return res;
    }
};

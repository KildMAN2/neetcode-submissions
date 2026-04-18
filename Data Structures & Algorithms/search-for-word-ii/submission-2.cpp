class Solution {
public:
int ROWS , COLS;
vector<vector<bool>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        vector<string>res;

        for (string word : words)
        {
            visited = vector<vector<bool>>(ROWS,vector<bool>(COLS,false));
            bool found = false;
            for(int r = 0 ; r < ROWS && !found ; r++)
            {
                for(int c = 0 ; c < COLS && !found ; c++)
                {
                    if(dfs(board , r ,c , 0 , word))
                    {
                        res.push_back(word);
                        found = true;
                    }
                }
            }
        }
        return res;  
    }
private: 
    bool dfs(vector<vector<char>> & board , int r , int c, int i ,string& word)
    {
        if(i == word.length())
        {
            return true;
        }
        if(c < 0 || r <0 || r>= ROWS || c >= COLS || board[r][c] != word[i] || visited[r][c])
        {
            return false;
        }
        visited[r][c] = true;
        bool res = dfs(board , r + 1 ,c , i + 1,word) ||
                   dfs(board , r - 1 ,c , i + 1,word) ||
                   dfs(board , r  ,c + 1, i + 1,word) ||
                   dfs(board , r  ,c - 1, i + 1,word);
        visited[r][c] = false;
        return res;
        
    }
};

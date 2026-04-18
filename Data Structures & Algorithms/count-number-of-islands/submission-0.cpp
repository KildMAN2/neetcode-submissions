class Solution {
    int directions[4][2] = {{1,0} , {-1,0} , {0 ,1} , {0, -1}};
public:
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS= grid.size() ; 
        COLS = grid[0].size();
        int islands = 0 ;
        for(int r = 0 ; r < ROWS; r++ )
        {
            for(int c =0 ; c < COLS; c++)
            {
                if(grid[r][c] == '1')
                {
                    bfs(grid , r ,c);
                    islands++;
                }
            }
        }
        return islands;   
    }
private: 
    void dfs(vector<vector<char>>& board , int r ,int c)
    {
        if(r < 0 || c < 0 || r >= ROWS || c>= COLS || board[r][c] == '0')
        {
            return;
        }
        board[r][c] = '0';
        for(int i = 0 ; i < 4 ; i++)
        {
            dfs(board, r + directions[i][0] , c + directions[i][1]);
        }
    }
    void bfs(vector<vector<char>> & grid , int r ,int c)
    {
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r,c});
        while(!q.empty())
        {
            pair <int,int> p = q.front(); q.pop();
            for(int i = 0 ; i< 4 ; i++)
            {
                int nr = p.first + directions[i][0];
                int nc = p.second + directions[i][1];
                if((nr >= 0 && nr < ROWS) && (nc >= 0 && nc < COLS) && 
                    grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr,nc});
                }
            }
        }
    }
};

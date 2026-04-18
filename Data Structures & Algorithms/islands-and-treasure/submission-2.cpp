class Solution {
    int directions[4][2] = { {-1 , 0 } , {1 , 0} , {0 ,1} ,{0 , -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int,int>> q; 

        for(int r = 0 ; r < ROWS ; r++)
        {
            for(int c = 0 ; c < COLS ; c++)
            {
                if(grid[r][c] == 0)
                {
                    q.push({r ,c});
                }
            }
        }
        vector<vector<bool>> visited(ROWS, vector(COLS , false));
        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nr = node.first + directions[i][0];
                int nc = node.second + directions[i][1];
                if((nr >= 0 && nr < ROWS) && (nc >= 0 && nc < COLS) && grid[nr][nc]> 0 && !visited[nr][nc])
                {
                    grid[nr][nc] = min(grid[nr][nc] , grid[node.first][node.second] + 1);
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }
        
    }
};

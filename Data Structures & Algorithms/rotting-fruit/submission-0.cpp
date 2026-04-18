class Solution {
    int directions[4][2] = {{1,0},{-1,0} , {0 ,1} , {0 , -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0 ;
        for(int r = 0 ; r < ROWS ; r++)
        {
            for(int c = 0 ; c < COLS ; c++)
            {
                if(grid[r][c] == 1)
                {
                    fresh++;
                }
                if( grid[r][c] == 2)
                {
                    q.push({r,c});
                    grid[r][c] = 0;
                }
            }
        }
        vector<vector<bool>> visited (ROWS,vector<bool>(COLS, false));
        while(!q.empty() && fresh>0)
        {
            pair<int,int> p = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nr = p.first + directions[i][0];
                int nc = p.second + directions[i][1];
                if((nr >=0 && nr < ROWS) && (nc >= 0 && nc < COLS) && grid[nr][nc] > 0  && !visited[nr][nc])
                {
                    grid[nr][nc] = max(grid[nr][nc],grid[p.first][p.second] + 1);
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                    fresh--;
                }
            }
        }
        int mx = 0;
        for (auto& row : grid)
            mx = max(mx, *max_element(row.begin(), row.end()));
        return (fresh == 0) ? mx : -1;
    }
};

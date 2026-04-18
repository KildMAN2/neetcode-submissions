class Solution {
    int directions[4][2] = {{1,0}, {-1,0} , {0,1} , {0 , -1}};
public:
int ROWS , COLS;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS  = grid[0].size();
        int maxArea = 0 ;
        for(int r = 0 ; r < ROWS ; r++)
        {
            for(int c = 0 ; c < COLS ; c++)
            {
                if(grid[r][c] == 1)
                {
                   int area =  bfs(grid, r ,c);
                   maxArea = max(area , maxArea);
                }
            }
        }
        return maxArea;
    }
private: 
    int dfs(vector<vector<int>> & grid , int r ,int c)
    {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || !grid[r][c])
        {
            return 0;
        }
        grid[r][c] = 0;
        int res = 1;
        for(int i = 0 ; i < 4 ; i++)
        {
            res +=  dfs(grid  , r + directions[i][0], c + directions[i][1]);
        }
        return res;
    }
    int bfs(vector<vector<int>> & grid , int r ,int c)
    {
        queue<pair<int,int>> q;
        grid[r][c] = 0;
        int res = 1;
        q.push({r,c});
        while(!q.empty())
        {
            pair<int,int> p = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nr = directions[i][0] + p.first;
                int nc = directions[i][1] + p.second;
                if((nr >= 0 && nr < ROWS) && (nc >= 0 && nc< COLS) && grid[nr][nc] == 1)
                {
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
    int directions[4][2] = {{1,0} , {-1,0} , {0 ,1} , {0,-1}};
public:
    int ROWS, COLS;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int maxLength = 0; 
        for(int r = 0; r < ROWS ; r++)
        {
            for(int c =0 ; c < COLS ; c++)
            {
                if(grid[r][c] == 1)
                {
                    maxLength = max(maxLength , bfs(grid, r, c));
                }
            }
        }
        return maxLength;
        
    }
private: 
    int bfs(vector<vector<int>> & grid , int r ,int c)
    {
        queue<pair<int,int>> q ;
        q.push({r ,c});
        grid[r][c] = 0 ;
        int res =1 ;
        while(!q.empty())
        {
             auto node = q.front() ; q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
               
                int nr = node.first + directions[i][0];
                int nc = node.second + directions[i][1];
                if((nr >= 0 && nr < ROWS) && (nc>= 0 && nc < COLS) && grid[nr][nc] == 1)
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

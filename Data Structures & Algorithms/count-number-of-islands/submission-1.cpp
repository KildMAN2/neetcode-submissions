class Solution {
    int directions[4][2] = {{1,0},{-1,0} , {0 , 1} , {0 , -1}};
public:
    int ROWS , COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int islands = 0 ;
        for(int r = 0 ; r < ROWS; r++)
        {
            for(int c = 0 ; c < COLS ; c++)
            {
                if(grid[r][c] == '1')
                {
                    bfs(grid ,r ,c);
                    islands++;
                }
            }
        }
        return islands;
        
    }
private: 
    void bfs(vector<vector<char>>& grid , int r ,int c)
    {
        queue<pair<int , int>>q ;
        q.push({r,c});
        grid[r][c] = '0'; 
        while(!q.empty())
        {
            auto node = q.front() ; q.pop();
            int row = node.first; 
            int col = node.second;
            for(int i = 0 ; i < 4 ; i++)
            {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if((nr >= 0 && nr < ROWS) && (nc >= 0 && nc < COLS) && grid[nr][nc] == '1')
                {
                    q.push({nr , nc});
                    grid[nr][nc] = 0 ;  
                }
            }
        }

    }
};

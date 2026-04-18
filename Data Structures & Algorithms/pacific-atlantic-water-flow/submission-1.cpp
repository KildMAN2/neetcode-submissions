class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int ROWS,COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> atlantic , pacific;
        atlantic =  vector<vector<bool>>(ROWS,vector<bool>(COLS,false));
        pacific =  vector<vector<bool>>(ROWS,vector<bool>(COLS,false));

        for(int cl  = 0 ; cl <COLS ; cl++ )
        {
            bfs(heights,0 , cl , pacific);
        }
        for(int rl  = 0 ; rl <ROWS ; rl++ )
        {
            bfs(heights,rl , 0 , pacific);
        }
        //ocean
        for(int cl  = 0 ; cl <COLS ; cl++ )
        {
            bfs(heights,ROWS -1 , cl , atlantic);
        }
        for(int rl  = 0 ; rl <ROWS ; rl++ )
        {
            bfs(heights,rl , COLS - 1 , atlantic);
        }
        vector<vector<int>> res;
        for(int r = 0 ; r < ROWS; r++ )
        {
            for(int c = 0 ; c<COLS ; c++)
            {
                if(pacific[r][c] && atlantic[r][c] )
                {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
private:
    void bfs(vector<vector<int>>& grid , int r , int c , vector<vector<bool>>& visited)
    {
        queue<pair<int,int>> q ;
        q.push({r,c});
        visited[r][c] = true;
        while(!q.empty())
        {
            pair<int,int> p = q.front(); q.pop();
            int ir = p.first;
            int ic = p.second;
            for(int i = 0; i < 4 ; i++)
            {
                int nr = ir  + directions[i][0];
                int nc = ic  + directions[i][1];
                if((nr >=0 && nr < ROWS) && (nc >= 0 && nc < COLS) && grid[nr][nc] >= grid[ir][ic] && !visited[nr][nc])
                {
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }
        // bool pacific = false ;
        // bool atlantic = false;
        // for(int cl : visited[0])
        // {
        //     if(cl) pacific = true;
        // }
        // for(int rl  = 0 ; rl <ROWS ; rl++ )
        // {
        //     if(visited[rl][0]) pacific = true;
        // }
        // //ocean
        // for(int cl : visited[ROWS -1])
        // {
        //     if(cl) atlantic = true;
        // }
        // for(int rl  = 0 ; rl <ROWS ; rl++ )
        // {
        //     if(visited[rl][COLS -1]) atlantic = true;
        // }
        // return atlantic && pacific;
    }
};

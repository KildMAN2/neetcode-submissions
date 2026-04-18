class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int ROWS,COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            ROWS = heights.size();
            COLS = heights[0].size();
            vector<vector<int>> res;
            for(int r = 0 ; r < ROWS; r++ )
            {
                for(int c = 0 ; c<COLS ; c++)
                {
                    if(bfs(heights,r,c))
                    {
                        res.push_back({r,c});
                    }
                }
            }
            return res;
    }
private:
    bool bfs(vector<vector<int>>& grid , int r , int c)
    {
        queue<pair<int,int>> q ;
        vector<vector<bool>> visited (ROWS , vector<bool> (COLS, false));
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
                if((nr >=0 && nr < ROWS) && (nc >= 0 && nc < COLS) && grid[nr][nc] <= grid[ir][ic] && !visited[nr][nc])
                {
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }
        bool pacific = false ;
        bool atlantic = false;
        for(int cl : visited[0])
        {
            if(cl) pacific = true;
        }
        for(int rl  = 0 ; rl <ROWS ; rl++ )
        {
            if(visited[rl][0]) pacific = true;
        }
        //ocean
        for(int cl : visited[ROWS -1])
        {
            if(cl) atlantic = true;
        }
        for(int rl  = 0 ; rl <ROWS ; rl++ )
        {
            if(visited[rl][COLS -1]) atlantic = true;
        }
        return atlantic && pacific;
    }
};

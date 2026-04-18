class Solution {
    int directions[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
public:
    int ROWS,COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacefic (ROWS,vector(COLS,false));
        vector<vector<bool>> atlantic  (ROWS,vector(COLS,false));
        for(int cl =0 ;cl <COLS ; cl++)
        {
            bfs(heights , 0 ,cl , pacefic);
        }
        for(int r = 0 ; r < ROWS ; r++)
        {
            bfs(heights , r ,0 , pacefic);
        }
        for(int cl =0 ;cl <COLS ; cl++)
        {
            bfs(heights , ROWS-1 ,cl , atlantic);
        }
        for(int r = 0 ; r < ROWS ; r++)
        {
            bfs(heights , r ,COLS -1 , atlantic);
        }
        vector<vector<int>>res;
        for(int r = 0 ; r < ROWS; r++)
        {
            for(int c = 0 ;c <COLS ; c++)
            {
                if(atlantic[r][c] && pacefic[r][c] )
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
        queue<pair<int,int>> q;
        q.push({r ,c});
        visited[r][c] = true;
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int ir = p.first;
            int ic = p.second;
            for(int i = 0 ; i < 4; i++)
            {
                int nr = ir + directions[i][0];
                int nc = ic + directions[i][1];
                if((nc >= 0 && nc < COLS) &&(nr >=0 && nr < ROWS) && !visited[nr][nc] && (grid[nr][nc] >= grid[ir][ic]))
                {
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
};

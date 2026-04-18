class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool> visited(n,false);
        for(auto & edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res =0 ;
        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])
            {
                bfs(node,adj,visited);
                res++;
            }
        }
        return res;
        

    }
private:
    void bfs(int node , vector<vector<int>>& adj , vector<bool> & visited)
    {
        queue<int>q;
        q.push(node);
        visited[node] = true;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(int nei : adj[cur])
            {
                if(!visited[nei])
                {
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }

    }
};

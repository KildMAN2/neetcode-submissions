class Graph {
    private:
    unordered_map<int , unordered_set<int>> adj_list;
    bool hasPathDFS(int src , int dst, unordered_set<int> & visited)
    {
        if(src == dst)
        {
            return true;
        }
        visited.insert(src);
        for(const int & neighbor: adj_list[src])
        {
            if(visited.find(neighbor) == visited.end())
            {
                if(hasPathDFS(neighbor, dst,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPathBFS(int src , int dst)
    {
        unordered_set<int>visited;
        deque <int> queue = {src};
        while(queue.empty() == false)
        {
            int curr = queue.front();
            queue.pop_front();
            if(curr == dst)
            {
                return true;
            }
            visited.insert(curr);
            for(const int & neighbor : adj_list[curr])
            {
                if(visited.find(neighbor) == visited.end())
                {
                    queue.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return false;
    }
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adj_list[src].insert(dst);

    }

    bool removeEdge(int src, int dst) {
        if(adj_list[src].find(dst) == adj_list[src].end() ||
            adj_list.find(src) == adj_list.end())
            {
                return false;
            }
            adj_list[src].erase(dst);
            return true;

    }

    bool hasPath(int src, int dst) {
        unordered_set<int> visited;
        return hasPathDFS(src, dst, visited);

    }
};

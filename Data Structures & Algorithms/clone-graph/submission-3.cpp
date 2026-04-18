/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> map;
        return bfs(node , map);
        
    }
private: 
    Node * bfs(Node * node , unordered_map<Node * , Node*> & oldToNew)
    {
        if(node == nullptr) return nullptr;
        queue<Node*> q ;
        oldToNew[node] = new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            auto curr = q.front() ; q.pop();
            for(Node * nei : curr->neighbors)
            {
                if(oldToNew.find(nei) == oldToNew.end())
                {
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[nei]);
            }
        }
        return oldToNew[node];
    }
    Node * dfs(Node * node , unordered_map<Node*,Node*> & oldToNew)
    {
        if(node == nullptr) return nullptr;
        if(oldToNew.count(node))
        {
            return oldToNew[node];
        }
        Node * copy = new Node(node->val);
        oldToNew[node]= copy;
        
        for(Node * nei : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei,oldToNew));
        }
        return copy;
    }
    
};

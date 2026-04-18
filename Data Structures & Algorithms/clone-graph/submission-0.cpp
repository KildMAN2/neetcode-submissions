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
        unordered_map<Node*, Node*> oldToNew;
        return bfs(node , oldToNew);
        
    }
private: 
    Node * dfs(Node * node , unordered_map<Node*,Node*> & oldToNew)
    {
        if(node == nullptr) return nullptr;
        if(oldToNew.count(node))
        {
            return oldToNew[node];
        }
        Node * copy = new Node(node->val);
        oldToNew[node] = copy;
        for(Node * nei : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei,oldToNew));
        }
        return copy;
    }
    Node * bfs(Node * node,unordered_map<Node*,Node*> & copyToNew )
    {
        if(node == nullptr) return nullptr;
        queue<Node*> q ; 
        q.push(node);
        Node * copy = new Node(node->val);
        copyToNew[node] = copy;
        while(!q.empty())
        {
            Node * n = q.front(); q.pop();
            if(n != nullptr)
            {
              for(Node * nei : n->neighbors)
              {
                if(copyToNew.find(nei) == copyToNew.end())
                {
                    q.push(nei);
                    copyToNew[nei] = new Node(nei->val);
                }
                copyToNew[n]->neighbors.push_back(copyToNew[nei]);
              }  
            }
        }
        return copyToNew[node];
    }
};

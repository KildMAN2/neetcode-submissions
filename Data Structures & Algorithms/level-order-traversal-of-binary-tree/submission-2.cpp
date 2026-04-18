/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level; 
            for(int i = 0 ; i < size; i++)
            {
                TreeNode* toAdd = q.front();
                q.pop();
                if(toAdd)
                {
                    level.push_back(toAdd->val);
                    q.push(toAdd->left);
                    q.push(toAdd->right);
                }
            }
            if(level.size()>0)
            {
                res.push_back(level);
            }
            
        }
        return res;
        
    }
};

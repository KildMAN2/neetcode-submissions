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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root == nullptr)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            TreeNode * rightNode;
            for(int i = 0 ; i < size; i++)
           { 
             rightNode = q.front();
             q.pop();
             if(rightNode->left) q.push(rightNode->left);
             if(rightNode->right) q.push(rightNode->right);
            }
            if(rightNode != nullptr)
            {
                res.push_back(rightNode->val);
            }
        }
        return res;
        
    }
};

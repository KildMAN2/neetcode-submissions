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
    vector<int>res;
    int kthSmallest(TreeNode* root, int k) {
        preorder(root);
        if(res.empty()) return -1;
        return res[k - 1];
        
    }
private:
    void preorder(TreeNode * root)
    {
        if(!root) return;
        preorder(root->left);
        res.push_back(root->val);
        preorder(root->right);
    }
};

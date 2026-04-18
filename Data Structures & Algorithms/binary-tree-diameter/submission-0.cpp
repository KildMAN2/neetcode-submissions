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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0; 
        inorder (root , res);
        return res;
        
    }
private:
    int inorder(TreeNode * root , int &res)
    {
        if(root == nullptr) return 0;
        int left = inorder(root->left,res);
        int right = inorder(root->right,res);
        res = max(res , left + right);
        return 1 + max(left,right);
    }
};

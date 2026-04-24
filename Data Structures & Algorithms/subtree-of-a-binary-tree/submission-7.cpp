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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(isSameTree(root,subRoot))return true;
        bool left = isSubtree(root->left , subRoot);
        bool right = isSubtree(root->right , subRoot);
        return left || right;

        
    }
private:
    bool isSameTree(TreeNode * p , TreeNode * q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return q->val == p->val && isSameTree(p->left,q->left) &&
                    isSameTree(p->right,q->right);
    }
};

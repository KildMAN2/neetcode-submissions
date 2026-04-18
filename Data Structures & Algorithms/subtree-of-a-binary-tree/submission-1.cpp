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
        if(subRoot == nullptr )
        {
            return true;
        }
        if(root == nullptr)
        {
            return false;
        }
        if(sameTree(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left , subRoot) || isSubtree(root->right,subRoot);
        
    }
    bool sameTree(TreeNode * t1 , TreeNode* t2)
    {
        if( t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        if(t1 != nullptr && t2 == nullptr)
        {
            return false;
        }
        if (t1 == nullptr && t2 != nullptr)
        {
            return false;
        }
        bool left = sameTree(t1->left , t2->left);
        bool right = sameTree (t1->right , t2->right);
        return right && left && t1->val == t2->val ;
    }
};

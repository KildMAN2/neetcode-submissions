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
    bool isBalanced(TreeNode* root) {
        return inorder(root)[0] == 1;
        
    }
    vector<int> inorder(TreeNode * root)
    {
        if(root == nullptr)  return {1,0};

        vector<int> left = inorder(root->left);
        vector<int> right = inorder(root->right);
        bool balanced = (left[0] == 1 && right[0] == 1 &&
                            abs(right[1] - left[1]) <= 1);
        int height = 1 + max(left[1],right[1]);
        return {balanced ? 1 : 0, height};
    }
};

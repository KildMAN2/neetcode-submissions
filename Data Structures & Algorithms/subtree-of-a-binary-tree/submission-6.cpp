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
        if(root == nullptr) return false;
        if(isSameTree(root , subRoot)) return true;
        return (isSubtree(root->left, subRoot)) 
                || isSubtree(root->right,subRoot);
        
    }
private: 
    bool isSameTree(TreeNode * q , TreeNode* p)
    {
        if(!q && !p) return true;
        if((!q && p) || (q && !p)) return false;
        bool left = isSameTree(q->left , p->left);
        bool right = isSameTree(q->right, p->right);
        return right && left && q->val == p->val;
    }
};
/*
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, s2;
        serialize(root, s1);
        serialize(subRoot, s2);
        return s1.find(s2) != string::npos;
    }

private:
    void serialize(TreeNode* node, string& s) {
        if (!node) {
            s += "#,";              // null marker
            return;
        }
        s += to_string(node->val) + ",";
        serialize(node->left, s);
        serialize(node->right, s);
    }
};

*/

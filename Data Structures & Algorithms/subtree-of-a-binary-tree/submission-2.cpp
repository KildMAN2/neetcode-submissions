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
    /*
      void serialize(TreeNode* node, std::string& s) {
        if (!node) {
            s += "#,"; // Edge case: null node marker
            return;
        }
        s += std::to_string(node->val) + ",";
        serialize(node->left, s);
        serialize(node->right, s);
    }

    // Returns true if subRoot is a subtree of root.
    // Handles edge cases: if subRoot is nullptr, always true; if root is nullptr, only true if subRoot is also nullptr.
    // 
    // Time Complexity: O(N + M), where N is the number of nodes in root and M is the number of nodes in subRoot.
    //   - Each tree is traversed once for serialization.
    //   - Substring search (find) is O(N + M) using standard library implementation (often uses efficient algorithms like KMP).
    // Space Complexity: O(N + M) for storing the serialized strings.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string sRoot, sSubRoot;
        serialize(root, sRoot);
        serialize(subRoot, sSubRoot);
        // Return true if serialized subRoot is a substring of serialized root
        return sRoot.find(sSubRoot) != std::string::npos;
    }
    */
};

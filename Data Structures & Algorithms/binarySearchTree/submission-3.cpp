class TreeNode
{
    public:
    int key; 
    int val; 
    TreeNode * left;
    TreeNode * right;

    TreeNode(int key , int val)
    {
        this->key = key; 
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class TreeMap {
    private: 
    TreeNode * root;
    TreeNode * findMin (TreeNode * node)
    {
        while(node != nullptr && node->left != nullptr )
        {
            node = node->left;
        }
        return node;
    }
    TreeNode * removeHelper (TreeNode * curr, int key)
    {
        if(curr == nullptr)
        {
            return nullptr;
        }
        if(key > curr->key)
        {
            curr->right = removeHelper(curr->right , key);
        }
        else if (key < curr->key) 
        {
            curr->left = removeHelper(curr->left , key);
        }
        else
        {
             if (curr->left == nullptr)
            {
                return curr->right ;

            }
            else if (curr->right == nullptr)
             {
                    return curr->left;
             }
            else
                {
                    TreeNode * minNode = findMin(curr->right);
                     curr->key = minNode->key;
                    curr->val = minNode->key;
                     curr->right = removeHelper(curr->right, minNode->key);
                }
        }
        return curr;

    }

    void inorderTraversal(TreeNode * root , vector<int> & result)
    {
        if(root != nullptr)
        {
            inorderTraversal(root->left , result);
            result.push_back(root->key);
            inorderTraversal(root ->right , result);
        }
    }

public:
    TreeMap() {
        root = nullptr;  
    }

    void insert(int key, int val) {
        TreeNode * toAdd = new TreeNode(key , val);
        if(root == nullptr)
        {
            root = toAdd;
            return;
        }
        TreeNode * current = root;
        while (true)
        {
            if(key < current-> key)
            {
                if(current->left == nullptr)
                {
                    current->left = toAdd;
                    return;
                }
                current = current->left;
            }
            else if (key > current->key)
            {
                if(current->right == nullptr)
                {
                    current->right = toAdd;
                    return;
                }
                current = current->right;
            }
            else
            {
                current->val = val;
                return;
            }
        }

    }

    int get(int key) {
        TreeNode * current = root;
        while(current != nullptr)
        {
            if(current->key < key)
            {
                current = current->right;
            }
            else if (current->key > key)
            {
                current = current->left;
            }
            else
            {
                return current->val;
            }
        }
        return -1;

    }

    int getMin() {
        TreeNode* current = root;
        while(current != nullptr && current->left != nullptr)
        {
            current = current->left;
        }
        return (current != nullptr) ? current->val : -1;

    }

    int getMax() {
        TreeNode * current = root;
        while(current != nullptr && current->right != nullptr)
        {
            current = current->right;
        }
        return (current != nullptr) ? current->val : -1;

    }

    void remove(int key) {
       root =  removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> res;
        inorderTraversal(root,res);
        return res;
    
    }
};

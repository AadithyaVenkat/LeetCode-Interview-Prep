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
class BSTIterator {
public:
    vector<int> result;
    int i=0;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        
        inorder(root);
        
    
    }
    
    /** @return the next smallest number */
    int next() {
        return result[i++];
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        if(i!=result.size())
            return true;
        else
            return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

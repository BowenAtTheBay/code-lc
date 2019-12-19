/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        else if (!l || !r)
            return false;
        else if (l->val == r->val)
            return helper(l->left, r->right) && helper(l->right, r->left);
        else
            return false;
    }
};
            return true;
​
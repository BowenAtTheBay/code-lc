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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return helper(root, 0);
    }
    
    int helper(TreeNode* node, int sum) {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return sum * 10 + node->val;
        
        sum = sum * 10 + node->val;
        return helper(node->left, sum) + helper(node->right, sum);
    }
};
​
//https://www.cnblogs.com/grandyang/p/4273700.html
//http://rainykat.blogspot.com/2017/03/leetcode-129-sum-root-to-leaf-numbersdfs.html
​
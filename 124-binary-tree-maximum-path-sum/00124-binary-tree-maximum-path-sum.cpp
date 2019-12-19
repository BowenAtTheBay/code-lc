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
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int sum = INT_MIN;
        pathsum_helper(root, sum);
        
        return sum;
    }
    
    int pathsum_helper(TreeNode* node, int& sum) {
        if (!node)
            return 0;
        
        int left = max(pathsum_helper(node->left, sum), 0);
        int right = max(pathsum_helper(node->right, sum), 0);
        
        sum = max(sum, left + right + node->val); // why left+right?
        
        return max(left, right) + node->val;
    }
};
​
/**
  -1
  / \
 3   5
  \   \
   -2  6
*/
​
//https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39775/Accepted-short-solution-in-Java
​
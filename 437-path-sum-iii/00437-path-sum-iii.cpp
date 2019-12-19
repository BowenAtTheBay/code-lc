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
    int pathSum(TreeNode* root, int sum) {
        if (!root) 
            return 0;
        
        // dfs for itself, and adding the result of both future left and right child
        return pathSum(root->left, sum) + pathSum(root->right, sum) + helper_pathsum(root, sum);
    }
    
    //sum just sum, not &sum
    int helper_pathsum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        int retval = 0;
        if (sum == root->val)
            ++retval;
        retval += helper_pathsum(root->left, sum - root->val);
        retval += helper_pathsum(root->right, sum - root->val);
​
        return retval;
    }
};
​
//https://leetcode.com/problems/path-sum-iii/discuss/91884/Simple-AC-Java-Solution-DFS
//https://leetcode.com/problems/path-sum-iii/discuss/91877/C%2B%2B-5-Line-Body-Code-DFS-Solution
​
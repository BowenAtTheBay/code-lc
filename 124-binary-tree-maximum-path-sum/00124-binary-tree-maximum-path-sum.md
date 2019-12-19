---
tags: ["leetcode","tree","depth-first search"]
created: "12/17/2019"
difficulty: "hard"
questionId: "00124"
questionName: "binary-tree-maximum-path-sum"
---

# <a href="https://leetcode.com/problems/binary-tree-maximum-path-sum/" target="_blank">00124-binary-tree-maximum-path-sum</a>

## Problem
<div><p>Given a <strong>non-empty</strong> binary tree, find the maximum path sum.</p>

<p>For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain <strong>at least one node</strong> and does not need to go through the root.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,2,3]

       <strong>1</strong>
      <strong>/ \</strong>
     <strong>2</strong>   <strong>3</strong>

<strong>Output:</strong> 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [-10,9,20,null,null,15,7]

&nbsp;  -10
&nbsp; &nbsp;/ \
&nbsp; 9 &nbsp;<strong>20</strong>
&nbsp; &nbsp; <strong>/ &nbsp;\</strong>
&nbsp; &nbsp;<strong>15 &nbsp; 7</strong>

<strong>Output:</strong> 42
</pre>
</div>

## Solution

c++
```c++
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
```

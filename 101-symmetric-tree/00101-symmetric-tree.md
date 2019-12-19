---
tags: ["leetcode","tree","depth-first search","breadth-first search"]
created: "12/17/2019"
difficulty: "easy"
questionId: "00101"
questionName: "symmetric-tree"
---

# <a href="https://leetcode.com/problems/symmetric-tree/" target="_blank">00101-symmetric-tree</a>

## Problem
<div><p>Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).</p>

<p>For example, this binary tree <code>[1,2,2,3,4,4,3]</code> is symmetric:</p>

<pre>    1
   / \
  2   2
 / \ / \
3  4 4  3
</pre>

<p>&nbsp;</p>

<p>But the following <code>[1,2,2,null,3,null,3]</code> is not:</p>

<pre>    1
   / \
  2   2
   \   \
   3    3
</pre>

<p>&nbsp;</p>

<p><b>Note:</b><br>
Bonus points if you could solve it both recursively and iteratively.</p>
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
```

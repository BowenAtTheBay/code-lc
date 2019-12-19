---
tags: ["leetcode","tree"]
created: "12/17/2019"
difficulty: "easy"
questionId: "00437"
questionName: "path-sum-iii"
---

# <a href="https://leetcode.com/problems/path-sum-iii/" target="_blank">00437-path-sum-iii</a>

## Problem
<div><p>You are given a binary tree in which each node contains an integer value.</p>

<p>Find the number of paths that sum to a given value.</p>

<p>The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).</p>

<p>The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

</p><p><b>Example:</b>
</p><pre>root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    <b>5</b>   <b>-3</b>
   <b>/</b> <b>\</b>    <b>\</b>
  <b>3</b>   <b>2</b>   <b>11</b>
 / \   <b>\</b>
3  -2   <b>1</b>

Return 3. The paths that sum to 8 are:

1.  5 -&gt; 3
2.  5 -&gt; 2 -&gt; 1
3. -3 -&gt; 11
</pre>
<p></p></div>

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
```

---
tags: ["leetcode","dynamic programming","tree"]
created: "12/18/2019"
difficulty: "medium"
questionId: "00095"
questionName: "unique-binary-search-trees-ii"
---

# <a href="https://leetcode.com/problems/unique-binary-search-trees-ii/" target="_blank">00095-unique-binary-search-trees-ii</a>

## Problem
<div><p>Given an integer <em>n</em>, generate all structurally unique <strong>BST's</strong> (binary search trees) that store values 1 ...&nbsp;<em>n</em>.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong>
[
&nbsp; [1,null,3,2],
&nbsp; [3,2,null,1],
&nbsp; [3,1,null,null,2],
&nbsp; [2,1,3],
&nbsp; [1,null,2,null,3]
]
<strong>Explanation:</strong>
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode* >();
        return helper_generator(1, n);
    }
    
    vector<TreeNode*> helper_generator(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(nullptr);
            printf("%d > %d\n", l, r);
        }
        else if (l == r) {
            res.push_back(new TreeNode(l));
            printf("push %d\n", l);
        }
        else {
            for (int i = l; i <= r; ++i) {
                printf("i=%d, l=%d, r=%d\n", i, l, r);
                vector<TreeNode*> left = helper_generator(l, i - 1); //?
                vector<TreeNode*> right = helper_generator(i + 1, r); //?
                
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j]; //?
                        root->right = right[k]; //?
                        printf("j=%d, k=%d, root=%d, left=%d, right=%d\n", j, k, root->val, left[j] ? left[j]->val : 0, right[k] ? right[k]->val : 0);
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
​
//https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31563/My-Accepted-C%2B%2B-solution-(recursive-less-than-30-lines)
//https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31575/24ms-c%2B%2B-easy-understanding-solution
//https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31516/Share-a-C%2B%2B-DP-solution-with-O(1)-space
​
```

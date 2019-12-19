---
tags: ["leetcode","tree","design"]
created: "12/17/2019"
difficulty: "hard"
questionId: "00297"
questionName: "serialize-and-deserialize-binary-tree"
---

# <a href="https://leetcode.com/problems/serialize-and-deserialize-binary-tree/" target="_blank">00297-serialize-and-deserialize-binary-tree</a>

## Problem
<div><p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>

<p><strong>Example:&nbsp;</strong></p>

<pre>You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as <code>"[1,2,3,null,null,4,5]"</code>
</pre>

<p><strong>Clarification:</strong> The above format is the same as <a href="/faq/#binary-tree">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p><strong>Note:&nbsp;</strong>Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.</p>
</div>

## Solution

c++
```c++

    TreeNode* deserialize(string data) {
        if (data == "/")
            return nullptr;
        stringstream s(data);
        return helper_deserialize(s);
    }
    
private:
    TreeNode* helper_deserialize(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "/")
            return nullptr;
        else {
            TreeNode* node = new TreeNode(stoi(str));
            node->left = helper_deserialize(s);
            node->right = helper_deserialize(s);
            return node;
        }
    }
};
​
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
​
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74252/Clean-C%2B%2B-solution
​
```

---
tags: ["leetcode","linked list"]
created: "12/19/2019"
difficulty: "medium"
questionId: "00092"
questionName: "reverse-linked-list-ii"
---

# <a href="https://leetcode.com/problems/reverse-linked-list-ii/" target="_blank">00092-reverse-linked-list-ii</a>

## Problem
<div><p>Reverse a linked list from position <em>m</em> to <em>n</em>. Do it in one-pass.</p>

<p><strong>Note:&nbsp;</strong>1 ≤ <em>m</em> ≤ <em>n</em> ≤ length of list.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, <em>m</em> = 2, <em>n</em> = 4
<strong>Output:</strong> 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;NULL
</pre>
</div>

## Solution

c++
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
        dummy->next = head;
        
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        cur = pre->next;
        for (int i = m; i < n; ++i) {
            //reverse linked link - practice
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return dummy->next;
    }
};
​
```

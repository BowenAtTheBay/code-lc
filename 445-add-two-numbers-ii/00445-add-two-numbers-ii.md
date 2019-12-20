---
tags: ["leetcode","linked list"]
created: "12/19/2019"
difficulty: "medium"
questionId: "00445"
questionName: "add-two-numbers-ii"
---

# <a href="https://leetcode.com/problems/add-two-numbers-ii/" target="_blank">00445-add-two-numbers-ii</a>

## Problem
<div><p>You are given two <b>non-empty</b> linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.</p>

<p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>

<p><b>Follow up:</b><br>
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
</p>

<p>
<b>Example:</b>
</p><pre><b>Input:</b> (7 -&gt; 2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)
<b>Output:</b> 7 -&gt; 8 -&gt; 0 -&gt; 7
</pre>
<p></p></div>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* prev = nullptr, *curr = nullptr;
        
        while (s1.size() || s2.size() || carry) {
            int sum = carry;
            if (s1.size()) {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            int n = sum % 10;
            
            prev = new ListNode(n);
            prev->next = curr; // first iteration: curr->null
            curr = prev; ////curr is the newly added node now
        }
        return curr;
    }
};
​
```

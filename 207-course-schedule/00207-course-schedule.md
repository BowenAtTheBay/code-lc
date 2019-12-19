---
tags: ["leetcode","depth-first search","breadth-first search","graph","topological sort"]
created: "12/18/2019"
difficulty: "medium"
questionId: "00207"
questionName: "course-schedule"
---

# <a href="https://leetcode.com/problems/course-schedule/" target="_blank">00207-course-schedule</a>

## Problem
<div><p>There are a total of <i>n</i> courses you have to take, labeled from <code>0</code> to <code>n-1</code>.</p>

<p>Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: <code>[0,1]</code></p>

<p>Given the total number of courses and a list of prerequisite <b>pairs</b>, is it possible for you to finish all courses?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 2, [[1,0]] 
<strong>Output: </strong>true
<strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. 
&nbsp;            To take course 1 you should have finished course 0. So it is possible.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 2, [[1,0],[0,1]]
<strong>Output: </strong>false
<strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. 
&nbsp;            To take course 1 you should have finished course 0, and to take course 0 you should
&nbsp;            also have finished course 1. So it is impossible.
</pre>

<p><b>Note:</b></p>

<ol>
	<li>The input prerequisites is a graph represented by <b>a list of edges</b>, not adjacency matrices. Read more about <a href="https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs" target="_blank">how a graph is represented</a>.</li>
	<li>You may assume that there are no duplicate edges in the input prerequisites.</li>
</ol>
</div>

## Solution

c++
```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int>());
        vector<int> visit(numCourses);
        
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs_helper(graph, visit, i))
                return false;
        }
        
        return true;
    }
    
    bool dfs_helper(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1)
            return false;
        if (visit[i] == 1)
            return true;
        
        visit[i] = -1;
        
        for (auto a : graph[i]) {
            if (!dfs_helper(graph, visit, a))
                return false;
        }
        
        visit[i] = 1;
        return true;
    }
};
//DAG - directed acyclic graph
//https://www.cnblogs.com/grandyang/p/4484571.html
//https://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/
//https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS
​
```

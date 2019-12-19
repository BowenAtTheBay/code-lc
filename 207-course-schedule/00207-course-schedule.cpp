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
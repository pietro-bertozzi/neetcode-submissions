class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> notyet(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            notyet[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!notyet[i]) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            result.push_back(curr);
            for (int n : adj[curr]) {
                if (!--notyet[n]) q.push(n);
            }
        }
        return !numCourses ? result : vector<int>{};
    }
};

class Solution {
public:
    set<int> visited;
    vector<vector<int>> adj;

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1) && visited.size() == n;
    }

    bool dfs(int node, int parent) {
        if (visited.count(node)) return false;
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (!dfs(neighbor, node)) return false;
        }
        return true;
    }
};
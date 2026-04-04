/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> old_copy;
        return dfs(node, old_copy);
    }

    Node* dfs(Node* node, map<Node*, Node*>& old_copy) {
        if (!node) return nullptr;
        if (old_copy.count(node)) return old_copy[node];
        Node* copy = new Node(node->val);
        old_copy[node] = copy;
        for (Node* n : node->neighbors) {
            copy->neighbors.push_back(dfs(n, old_copy));
        }
        return copy;
    }
};
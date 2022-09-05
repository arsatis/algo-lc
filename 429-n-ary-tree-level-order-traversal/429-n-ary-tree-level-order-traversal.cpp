/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        ios_base::sync_with_stdio(0);
        
        if (!root) return {};
        vector<vector<int>> levels;
        queue<pair<int, Node*>> q;
        q.emplace(0, root);
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            if (levels.size() == p.first) levels.push_back({p.second->val});
            else levels.back().push_back(p.second->val);
            for (Node* child : p.second->children) q.emplace(p.first + 1, child);
        }
        return levels;
    }
};
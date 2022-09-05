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
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        if (!root) return {};
        vector<vector<int>> levels;
        queue<Node*> q;
        q.emplace(root);
        
        while (!q.empty()) {
            int size = q.size();
            levels.push_back({});
            
            while (size--) {
                Node* node = q.front(); q.pop();
                levels.back().emplace_back(node->val);
                for (Node* child : node->children) q.emplace(child);
            }
        }
        return levels;
    }
};
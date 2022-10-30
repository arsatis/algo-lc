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
        if (!root) return {};
        vector<vector<int>> output;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            output.emplace_back(vector<int>());
            while (size--) {
                Node* node = q.front();
                q.pop();
                output.back().emplace_back(node->val);
                for (Node* child : node->children) q.emplace(child);
            }
        }
        return move(output);
    }
};
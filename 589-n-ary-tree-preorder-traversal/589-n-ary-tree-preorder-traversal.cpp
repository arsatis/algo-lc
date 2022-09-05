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
    void f(Node* node, vector<int>& output) {
        if (!node) return;
        output.push_back(node->val);
        for (Node* child : node->children) f(child, output);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> output;
        f(root, output);
        return output;
    }
};
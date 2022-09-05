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
    vector<int> output;
public:
    vector<int> preorder(Node* root) {
        ios_base::sync_with_stdio(0);
        
        if (!root) return {};
        output.push_back(root->val);
        for (Node* child : root->children) preorder(child);
        return output;
    }
};
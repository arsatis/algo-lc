/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        ios_base::sync_with_stdio(0);
        
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node* curr = q.front();
                q.pop();
                if (n > 0) curr->next = q.front();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};
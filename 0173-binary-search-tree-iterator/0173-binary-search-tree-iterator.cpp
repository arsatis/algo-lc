/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            nodes.emplace(root);
            root = root->left;
        }
    }
    
    int next() {
        auto n = nodes.top();
        nodes.pop();
        if (n->right) {
            TreeNode* l = n->right;
            while (l) {
                nodes.emplace(l);
                l = l->left;
            }
        }
        return n->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
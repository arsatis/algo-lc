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
class Solution {
    vector<int> vals;
    void f(TreeNode* node) {
        if (node->left) f(node->left);
        vals.push_back(node->val);
        if (node->right) f(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        f(root);
        return vals;
    }
};
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
        vals.push_back(node->val);
        if (node->left) f(node->left);
        if (node->right) f(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        
        if (!root) return {};
        f(root);
        return vals;
    }
};
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
    vector<int> vi;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) helper(root);
        return vi;
    }
    
    void helper(TreeNode *node) {
        if (node->left) helper(node->left);
        vi.push_back(node->val);
        if (node->right) helper(node->right);
    }
};
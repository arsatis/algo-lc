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
    int f(TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right) return isLeft ? node->val : 0;
        return (node->left ? f(node->left, true) : 0) +
               (node->right ? f(node->right, false) : 0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root->left, true) + f(root->right, false);
    }
};
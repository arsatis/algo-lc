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
    bool balanced = true;
    int f(TreeNode* node) {
        if (!node) return 0;
        int left = f(node->left), right = f(node->right);
        balanced &= abs(left - right) <= 1;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        f(root);
        return balanced;
    }
};
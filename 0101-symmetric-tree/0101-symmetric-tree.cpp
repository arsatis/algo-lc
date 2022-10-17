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
    bool f(TreeNode* left, TreeNode* right) {
        if (!left || !right) return !left && !right;
        return left->val == right->val && f(left->left, right->right)
                                       && f(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return f(root->left, root->right);
    }
};
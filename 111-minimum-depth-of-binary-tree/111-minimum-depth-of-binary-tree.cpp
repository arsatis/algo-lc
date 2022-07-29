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
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return helper(root);
    }
    
    int helper(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        return 1 + min(root->left ? helper(root->left) : 99999, root->right ? helper(root->right) : 99999);
    }
};
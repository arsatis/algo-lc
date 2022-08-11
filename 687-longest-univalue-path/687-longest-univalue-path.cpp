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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int lh = helper(root->left, root->val);
        int rh = helper(root->right, root->val);
        return max(lh + rh, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
    
    int helper(TreeNode* node, int val) {
        if (!node || node->val != val) return 0;
        return 1 + max(helper(node->left, val), helper(node->right, val));
    }
};
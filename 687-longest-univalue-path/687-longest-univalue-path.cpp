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
        ios::sync_with_stdio(0);
        int mx = 0;
        helper(root, mx);
        return mx;
    }
    
    int helper(TreeNode* node, int& mx) {
        if (!node) return 0;
        int leftPath = helper(node->left, mx),
            rightPath = helper(node->right, mx);
        int left = node->left && node->left->val == node->val ? leftPath + 1 : 0,
            right = node->right && node->right->val == node->val ? rightPath + 1 : 0;
        mx = max(mx, left + right);
        return max(left, right);
    }
};
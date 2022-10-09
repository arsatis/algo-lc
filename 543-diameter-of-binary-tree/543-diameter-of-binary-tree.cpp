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
    int maxLen = 0;
    int f(TreeNode* node) {
        int left = node->left ? 1 + f(node->left) : 0,
            right = node->right ? 1 + f(node->right) : 0;
        maxLen = max(maxLen, left + right);
        return max(left, right);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxLen;
    }
};
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
        int left = node->left ? f(node->left) : 0, right = node->right ? f(node->right) : 0;
        balanced &= abs(left - right) <= 1;
        return 1 + max(left, right);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        f(root);
        return balanced;
    }
};
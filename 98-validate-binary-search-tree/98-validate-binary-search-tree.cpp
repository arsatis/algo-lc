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
    bool f(TreeNode* node, long lb, long ub) {
        if (!node) return true;
        return node->val > lb && node->val < ub
                              && f(node->left, lb, node->val)
                              && f(node->right, node->val, ub);
    }
public:
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        return f(root, LONG_MIN, LONG_MAX);
    }
};
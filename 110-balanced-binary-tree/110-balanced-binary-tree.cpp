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
    int check(TreeNode* root) {
        if (!root) return 0;
        int lh = check(root->left), rh = check(root->right);
        if (abs(lh - rh) > 1) return 1e9;
        return 1 + max(lh ,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        return check(root) >= 1e9 ? false : true;
    }
};
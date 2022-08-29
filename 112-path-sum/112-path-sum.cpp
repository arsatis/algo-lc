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
    bool solve(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right && targetSum - root->val == 0) return true;
        bool leftside = solve(root->left, targetSum - root->val);
        bool rightside = solve(root->right, targetSum - root->val);
        return leftside || rightside;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};
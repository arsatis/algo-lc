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
    int sum = 0;
    int rob(TreeNode* root) {
        if (!root) {
            sum = 0;
            return 0;
        }
        int l = rob(root->left);
        int preSum = sum;
        int r = rob(root->right);
        preSum += sum;
        sum = l + r;
        return max(root->val + preSum, sum);
    }
};
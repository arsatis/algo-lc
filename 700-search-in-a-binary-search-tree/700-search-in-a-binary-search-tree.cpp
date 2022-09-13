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
    TreeNode* searchBST(TreeNode* root, int val) {
        ios_base::sync_with_stdio(0);
        
        if (!root || root->val == val) return root;
        TreeNode* left = root->left ? searchBST(root->left, val) : nullptr;
        return left ? left : (root->right ? searchBST(root->right, val) : nullptr);
    }
};
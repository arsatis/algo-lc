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
    int ans = 0;
    void f(TreeNode* root, int& k) {
        if (root->left) f(root->left, k);
        if (--k == 0) ans = root->val;
        if (root->right) f(root->right, k);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        f(root, k);
        return ans;
    }
};
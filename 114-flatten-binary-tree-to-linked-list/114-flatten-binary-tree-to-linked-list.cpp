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
    void flatten(TreeNode *root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        while (root) {
            if (root->left && root->right) {
                TreeNode* t = root->left;
                while (t->right) t = t->right;
                t->right = root->right;
            }

            if (root->left) root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
};
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (root->right) {
                TreeNode* curr = root->right, *prev = nullptr;
                while (curr->left) prev = curr, curr = curr->left;
                root->val = curr->val;
                if (prev) prev->left = curr->right;
                else root->right = curr->right;
            } else if (root->left) {
                TreeNode* curr = root->left, *prev = nullptr;
                while (curr->right) prev = curr, curr = curr->right;
                root->val = curr->val;
                if (prev) prev->right = curr->left;
                else root->left = curr->left;
            } else return nullptr;
        }
        return root;
    }
};

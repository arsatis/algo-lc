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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q;
        q.emplace(root);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (depth == 2) {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                } else {
                    if (node->left) q.emplace(node->left);
                    if (node->right) q.emplace(node->right);
                }
            }
            --depth;
        }
        return root;
    }
};
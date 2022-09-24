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
    vector<vector<int>> paths;
    void f(TreeNode* node, int target, vector<int>& path) {
        target -= node->val;
        path.emplace_back(node->val);
        if (!target && !node->left && !node->right) paths.emplace_back(path);
        else {
            if (node->left) f(node->left, target, path);
            if (node->right) f(node->right, target, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> path;
        f(root, targetSum, path);
        return move(paths);
    }
};
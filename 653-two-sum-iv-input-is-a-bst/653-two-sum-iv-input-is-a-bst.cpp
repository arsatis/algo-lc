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
    unordered_set<int> comps;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (comps.find(root->val) != comps.end()) return true;
        comps.insert(k - root->val);
        return (root->left ? findTarget(root->left, k) : false) ||
               (root->right ? findTarget(root->right, k) : false);
    }
};
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
    int target;
    unordered_set<int> comps;
    bool f(TreeNode* node) {
        if (!node) return false;
        if (comps.find(node->val) != comps.end()) return true;
        comps.insert(target - node->val);
        return (node->left ? f(node->left) : false) || (node->right ? f(node->right) : false);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        ios_base::sync_with_stdio(0);
        
        target = k;
        return f(root);
    }
};
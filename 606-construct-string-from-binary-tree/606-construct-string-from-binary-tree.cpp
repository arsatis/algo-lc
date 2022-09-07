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
    string tree2str(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        
        string output = to_string(root->val);
        if (root->right) return output + "(" + (root->left ? tree2str(root->left) : "") + ")(" + tree2str(root->right) + ")";
        else if (root->left) return output + "(" + tree2str(root->left) + ")";
        else return output;
    }
};
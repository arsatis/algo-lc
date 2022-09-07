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
        string output = to_string(root->val),
               left = root->left ? tree2str(root->left) : "",
               right = root->right ? tree2str(root->right) : "";
        if (root->right) return output + "(" + left + ")(" + right + ")";
        else if (root->left) return output + "(" + left + ")";
        else return output;
    }
};
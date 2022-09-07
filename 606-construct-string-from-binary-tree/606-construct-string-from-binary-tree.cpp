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
    void f(TreeNode* root,string &res) {
        if (!root) return;

        res += to_string(root->val);
        if (!root->left && !root->right) return;
        
        if (root->right) {
            res += '(';
            f(root->left, res);
            res += ")(";
            f(root->right, res);
            res += ')';
        } else if (root->left) {
            res += '(';
            f(root->left, res);
            res += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        
        string res = "";
        f(root, res);
        return res;
    }
};
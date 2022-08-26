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
    TreeNode* head = nullptr, *prev = nullptr;
public:
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        dfs(root->left);
        if (!prev) head = root;
        else {
            root->right = prev;
            root->left = nullptr;
        }
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        dfs(root);
    }
};
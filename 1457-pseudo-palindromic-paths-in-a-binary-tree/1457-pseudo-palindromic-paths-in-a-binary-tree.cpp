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
    int nodes[10] = { 0 };
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int pseudoPalindromicPaths(TreeNode* root) {
        ++nodes[root->val];
        if (!root->left && !root->right) {
            int oddCount = 0;
            for (int i : nodes) if (i % 2 != 0) ++oddCount;
            --nodes[root->val];
            return oddCount > 1 ? 0 : 1;
        }
        
        int num = 0;
        if (root->left) num += pseudoPalindromicPaths(root->left);
        if (root->right) num += pseudoPalindromicPaths(root->right);
        --nodes[root->val];
        return num;
    }
};
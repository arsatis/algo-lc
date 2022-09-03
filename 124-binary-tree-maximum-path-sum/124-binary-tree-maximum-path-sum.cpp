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
    int f(TreeNode* root, int& ans){
        if(!root)
            return 0;
        
        int a = f(root->left, ans);
        if(a < 0) 
            a = 0;
        
        int b = f(root->right, ans);
        if(b < 0) 
            b = 0;
        
        ans = max(ans, root->val + a + b);
        return  root->val + max(a, b);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root, ans);
        return ans;
    }
};
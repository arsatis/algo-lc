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
    pair<int, int> f(TreeNode* root, int& ans) {
        if (!root) return { -1001, -1 };
        pair<int, int> p1 = f(root->left, ans), p2 = f(root->right, ans);
        int l = 0, r = 0;
        
        if (root->val == p1.first) l += (p1.second + 1);
        if (root->val == p2.first) r += (p2.second + 1);
        ans = max(ans, l + r);
        return { root->val, max(l, r) };
    }
    
    int longestUnivaluePath(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        f(root, ans);
        return ans;
    }
};
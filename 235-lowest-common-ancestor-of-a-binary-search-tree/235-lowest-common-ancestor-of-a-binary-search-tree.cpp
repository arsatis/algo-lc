/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int val = root->val;
        if (val < p->val && val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (val > p->val && val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
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
        
        while (root) {
            if (root->val < p->val && root->val < q->val) root = root->right;
            else if (root->val > p->val && root->val > q->val) root = root->left;
            else break;
        }
        return root;
    }
};
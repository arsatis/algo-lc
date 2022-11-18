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
    bool f(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q; 
        return p->val == q->val &&
            (p->right ? f(p->right, q->right) : p->right == q->right) &&
            (p->left ? f(p->left, q->left) : p->left == q->left);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root->val == subRoot->val && f(root, subRoot)) return true;
        return (root->left ? isSubtree(root->left, subRoot) : false) ||
               (root->right ? isSubtree(root->right, subRoot) : false);
    }
};

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
    TreeNode* f(vector<int>& in, vector<int>& post, unordered_map<int, int>& idx,
                int& p, int l, int r) {
        if (l > r) return nullptr;
        int val =  post[p--];
        TreeNode* node = new TreeNode(val);
        node->right = f(in, post, idx, p, idx[val] + 1, r);
        node->left = f(in, post, idx, p, l, idx[val] - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pIdx = postorder.size() - 1;
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); ++i) idx[inorder[i]] = i;
        return f(inorder, postorder, idx, pIdx, 0, inorder.size() - 1);
    }
};
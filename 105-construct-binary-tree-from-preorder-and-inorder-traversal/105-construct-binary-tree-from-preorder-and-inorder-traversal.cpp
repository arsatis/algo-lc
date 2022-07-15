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
    vector<int> preorder, inorder;
    int pi = 0;
    unordered_map<int, int> index;
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        for (int i = 0; i < inorder.size(); ++i) index[inorder[i]] = i;
        return helper(0, preorder.size());
    }
private:
    TreeNode *helper(int l, int r) {
        if (l == preorder.size() || l > r) return nullptr;
        int val = preorder[pi++];
        TreeNode *root = new TreeNode(val);
        root->left = helper(l, index[val] - 1);
        root->right = helper(index[val] + 1, r);
        return root;
    }
};
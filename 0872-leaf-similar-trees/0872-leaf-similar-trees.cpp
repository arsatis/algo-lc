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
    void f(vector<int>& arr, TreeNode* node) {
        if (!node->left && !node->right) arr.emplace_back(node->val);
        else {
            if (node->left) f(arr, node->left);
            if (node->right) f(arr, node->right);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        f(arr1, root1), f(arr2, root2);
        if (arr1.size() != arr2.size()) return false;
        for (int i = 0; i < arr1.size(); ++i) if (arr1[i] != arr2[i]) return false;
        return true;
    }
};

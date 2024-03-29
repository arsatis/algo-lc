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
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (1) {
            while (root) {
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};
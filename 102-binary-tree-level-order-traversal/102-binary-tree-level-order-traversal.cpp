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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        
        deque<pair<TreeNode*, int>> q;
        q.push_back(pair<TreeNode*, int>(root, 0));
        vector<vector<int>> output(1, vector<int>());
        int curr = 0;
        while (q.size() > 0) {
            auto &hi = q.front();
            if (curr != hi.second) {
                output.push_back(vector<int>());
                ++curr;
            }
            output[output.size() - 1].push_back(hi.first->val);
            if (hi.first->left) q.push_back(pair(hi.first->left, curr + 1));
            if (hi.first->right) q.push_back(pair(hi.first->right, curr + 1));
            q.pop_front();
        }
        return output;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> output;
        queue<TreeNode*> q;
        q.emplace(root);

        bool l2r = true;
        while (!q.empty()) {
            vector<int> tmp;
            int size = q.size();
            while (size--) {
                tmp.emplace_back(q.front()->val);
                if (q.front()->left) q.emplace(q.front()->left);
                if (q.front()->right) q.emplace(q.front()->right);
                q.pop();
            }
            if (l2r) output.emplace_back(tmp);
            else output.emplace_back(vector<int>(tmp.rbegin(), tmp.rend()));
            l2r = !l2r;
        }
        return move(output);
    }
};

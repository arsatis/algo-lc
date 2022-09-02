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
    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        
        int nodesInLevel = 0;
        vector<double> averages;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            
            if (averages.size() == node.second) {
                if (node.second > 0) averages[node.second - 1] /= nodesInLevel;
                nodesInLevel = 1;
                averages.push_back(node.first->val);
            } else {
                averages[node.second] += node.first->val;
                ++nodesInLevel;
            }
            
            if (node.first->left) q.emplace(node.first->left, node.second + 1);
            if (node.first->right) q.emplace(node.first->right, node.second + 1);
        }
        averages[averages.size() - 1] /= nodesInLevel;
        return averages;
    }
};
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
        
        int nodesInLevel, nodeLevel = -1;
        vector<double> averages;
        queue<TreeNode*> q;
        q.push(nullptr), q.push(root);
        
        while (q.size() > 1) {
            TreeNode* node = q.front(); q.pop();
            
            if (!node) {
                if (nodeLevel > 0) averages[nodeLevel] /= nodesInLevel;
                averages.push_back(0);
                nodesInLevel = 0;
                ++nodeLevel;
                q.push(nullptr);
            } else {
                averages[nodeLevel] += node->val;
                ++nodesInLevel;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        averages[nodeLevel] /= nodesInLevel;
        return averages;
    }
};
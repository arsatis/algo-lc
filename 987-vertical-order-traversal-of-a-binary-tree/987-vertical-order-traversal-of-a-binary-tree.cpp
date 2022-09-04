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
    map<int, vector<vector<int>>> columnIndex;
    void bfs(TreeNode* node, int col, int row) {
        if (!node) return;
        while (columnIndex[col].size() <= row) columnIndex[col].push_back({});
        columnIndex[col][row].push_back(node->val);
        bfs(node->left, col - 1, row + 1);
        bfs(node->right, col + 1, row + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        
        vector<vector<int>> output;
        bfs(root, 0, 0);
        for (auto& colRowPair : columnIndex) {
            output.push_back({});
            for (auto& row : colRowPair.second) {
                sort(row.begin(), row.end());
                output.back().insert(output.back().end(), row.begin(), row.end());
            }
        }
        return output;
    }
};
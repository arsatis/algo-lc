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
    unordered_map<string, int> visited;
    vector<TreeNode*> dups;

    string dfs(TreeNode* node) {
        string s = "(" + (node->left ? dfs(node->left) : "")
            + to_string(node->val)
            + (node->right ? dfs(node->right) : "") + ")";
        if (visited.count(s) && visited[s] == 1) dups.emplace_back(node);
        ++visited[s];
        return move(s);
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root) dfs(root);
        return move(dups);
    }
};

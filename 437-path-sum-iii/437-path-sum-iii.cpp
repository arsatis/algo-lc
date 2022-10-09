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
    int numPaths = 0, k;
    unordered_map<long, int> visited;
    
    void f(TreeNode* node, long curr) {
        curr += node->val;
        if (curr == k) ++numPaths;
        if (visited.find(curr - k) != visited.end())
            numPaths += visited[curr - k];
        
        ++visited[curr];
        if (node->left) f(node->left, curr);
        if (node->right) f(node->right, curr);
        --visited[curr];
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        k = targetSum;
        f(root, 0);
        return numPaths;
    }
};
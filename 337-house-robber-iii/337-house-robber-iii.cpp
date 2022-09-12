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
    
    pair<int,int> sum_robber_tree(TreeNode* node) {
        if(!node) {
            return {0,0};
        }
        
        auto&& left = sum_robber_tree(node->left);
        auto&& right = sum_robber_tree(node->right);
         
        int&& not_robbed = max(left.first, left.second) + max(right.first, right.second);
        
        int&& robbed =  node->val + left.second + right.second;
         
        return { robbed, not_robbed };
    }
    
    
public:
    int rob(TreeNode* root) {
         
        auto&& [robbed, not_robbed] = sum_robber_tree(root);
        
        return max(robbed, not_robbed);
    }
};
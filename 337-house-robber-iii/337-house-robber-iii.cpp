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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        if(mp.find(root)!=mp.end())
            return mp[root];
        //case 1 khud ko include kr rha hai
        int sum1=root->val;
        
        if(root->left !=NULL)
            sum1+=rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL)
            sum1+=rob(root->right->left)+rob(root->right->right);
        
        //case 2 current node not included
        int sum2=0;
        sum2+=rob(root->left)+rob(root->right);
        
        return mp[root]=max(sum1,sum2);
        
    }
};
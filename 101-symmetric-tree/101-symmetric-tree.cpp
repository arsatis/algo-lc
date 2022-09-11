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
    stack<int> leftStack,rightStack;
public:
    void recursiveLeft(TreeNode* root)
    {
        if(!root) return;
        if(!root->left ||!root-> right) leftStack.push(-101);
        recursiveLeft(root->left);
        leftStack.push(root->val);
        recursiveLeft(root->right);
    }
    void recursiveRight(TreeNode* root)
    {
        if(!root) return;
        if(!root->left ||!root-> right) rightStack.push(-101);
        recursiveRight(root->right);
        rightStack.push(root->val);
        recursiveRight(root->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        bool result;
        recursiveLeft(root->left);
        recursiveRight(root->right);
        if(leftStack.size()!=rightStack.size()) return false;
        while(!leftStack.empty()||!rightStack.empty())
        {
            cout<<leftStack.top()<<"/"<<rightStack.top()<<endl;
            if(leftStack.top()!=rightStack.top())
            {
                return false;
            }
            leftStack.pop();
            rightStack.pop();
        }
        return true;
    }
};
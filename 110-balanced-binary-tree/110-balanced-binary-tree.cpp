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
    int f(TreeNode* root){
        //base case
        if(root == NULL)
            return 0;
        
        int leftHeight = f(root->left);
        int rightHeight = f(root->right);

        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        
        return max(leftHeight, rightHeight) + 1;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;        
        if (f(root) == -1) return false;
        else return true;
    }
};
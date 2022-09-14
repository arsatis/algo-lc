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
  vector<int>v;
  void dfs(TreeNode* root){
    if(!root) return;
   
    dfs(root->left);
     v.push_back(root->val);
    dfs(root->right);
  }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
      dfs(root);
      int i=0;
      int j=v.size()-1;
      while(i<j){
        if(v[i]+v[j]==k) return true;
        else if(v[i]+v[j]<k) i++;
        else j--;
      }
      return false;
    }
};
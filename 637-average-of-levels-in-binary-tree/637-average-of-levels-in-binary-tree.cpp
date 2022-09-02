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
        vector<double> v;
         if(root==0)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int s=q.size();
            double sum=0;
        double  size=q.size();
            while(s--){
                
            TreeNode* t=q.front();
                sum+=t->val;
                q.pop();
             if(t->left)
                 q.push(t->left);
                if(t->right)
                    q.push(t->right);
                temp.push_back(t->val);
                
            }
            v.push_back(sum/size);
            
        }
        return v;
    }
};
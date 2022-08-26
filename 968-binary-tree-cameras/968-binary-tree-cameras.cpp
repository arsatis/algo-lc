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
    int traverse(TreeNode* node, bool header, int& numCam) {
        if (!node) return 0;
        if (!node->right && !node->left) { 
            if (header) ++numCam;
            return 1;
        }
        
        int leftVal = -1, rightVal = -1;
        if (node->left) leftVal = traverse(node->left, false, numCam);
        if (node->right) rightVal = traverse(node->right, false, numCam);
        if (leftVal == 1 || rightVal == 1) {
            ++numCam;
            return 2;
        } else if (leftVal == 2 || rightVal == 2) {            
            return 3;
        } else if (!header) {
            return 1;
        } else {
            ++numCam;
            return 0;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int numCam = 0;
        traverse(root, true, numCam);
        return numCam;
    }
};
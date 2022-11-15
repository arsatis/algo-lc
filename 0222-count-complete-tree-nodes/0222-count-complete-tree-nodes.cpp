// O(n) solution:
class Solution {
public:
    int countNodes(TreeNode* root) {
       if (!root) return 0;
       return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// O(log^2 n) solution:
class Solution {
    int rightDfs(TreeNode* node) {
        if (!node) return 0;
        if (!node->right) return 1;
        return 1 + (node->right ? rightDfs(node->right) : 0);
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        // find max height
        TreeNode* left = root->left, *right = root->right;
        int maxHeight = 0;
        while (left) left = left->left, ++maxHeight;
        left = root->left;

        // find whether tree is perfectly balanced
        int heightRight = rightDfs(right);
        if (maxHeight == heightRight) return (2 << maxHeight) - 1;
        
        // find number of leaf nodes
        int heightLeft = rightDfs(left), numLeaf = (1 << maxHeight) - 1;
        while (left) {
            if (maxHeight > heightLeft) right = left->right, left = left->left;
            else {
                numLeaf += (1 << (maxHeight - 1));
                if (!right) break;
                left = right->left, right = right->right;
            }
            heightLeft = rightDfs(left);
            --maxHeight;
        }
        return numLeaf;
    }
};

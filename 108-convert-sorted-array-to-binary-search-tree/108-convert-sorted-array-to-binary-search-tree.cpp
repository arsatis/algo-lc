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
    vector<int> nums;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return helper(0, nums.size());
    }
    
    TreeNode* helper(int left, int right) {
        if (right <= left) return NULL;
        if (right - left == 1) return new TreeNode(nums[left]);
        
        int mid = (left + right) / 2;
        TreeNode* l = helper(left, mid);
        TreeNode* r = helper(mid + 1, right);
        TreeNode* node = new TreeNode(nums[mid], l, r);
        return node;
    }
};
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
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (right <= left) return nullptr;
        if (right - left == 1) return new TreeNode(nums[left]);
        int mid = (left + right) >> 1;
        TreeNode* l = helper(nums, left, mid);
        TreeNode* r = helper(nums, mid + 1, right);
        TreeNode* node = new TreeNode(nums[mid], l, r);
        return node;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
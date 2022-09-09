class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        while (nums[0] != nums[nums[0]]) swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};
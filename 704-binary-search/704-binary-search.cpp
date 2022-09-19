class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int search(vector<int>& nums, int target) {
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
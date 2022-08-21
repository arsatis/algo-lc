class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
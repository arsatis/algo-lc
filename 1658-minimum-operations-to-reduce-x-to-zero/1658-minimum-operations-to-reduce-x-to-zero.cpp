class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, sumNew = 0, len = -1;
        for (int& i : nums) sum += i;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            sumNew += nums[right];
            while (left <= right && sumNew > sum - x) sumNew -= nums[left++];
            if (sumNew == sum - x) len = max(len, right - left + 1);
        }
        return len == -1 ? -1 : nums.size() - len;
    }
};
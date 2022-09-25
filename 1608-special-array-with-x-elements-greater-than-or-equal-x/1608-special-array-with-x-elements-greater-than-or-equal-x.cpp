class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count = 0, arr[1001] = { 0 };
        for (int i : nums) ++arr[i];
        for (int i = 0; i < 1001; ++i) {
            if (i == nums.size() - count) return i;
            count += arr[i];
        }
        return -1;
    }
};
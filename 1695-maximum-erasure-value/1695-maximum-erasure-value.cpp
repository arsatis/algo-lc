class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool arr[10001] = { false };
        int l = 0, r = 0, output = 0, currSum = 0;
        while (r < nums.size()) {
            while (arr[nums[r]]) {
                arr[nums[l]] = false;
                currSum -= nums[l++];
            }
            arr[nums[r]] = true;
            currSum += nums[r++];
            output = max(output, currSum);
        }
        return output;
    }
};
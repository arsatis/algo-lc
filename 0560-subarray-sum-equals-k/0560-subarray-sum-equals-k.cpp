class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefSums;
        int count = 0, prefSum = 0;
        ++prefSums[0];
        for (int x : nums) {
            prefSum += x;
            if (prefSums.count(prefSum - k)) count += prefSums[prefSum - k];
            ++prefSums[prefSum];
        }
        return count;
    }
};

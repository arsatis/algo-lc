#include <unordered_set>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i = 0;

        for (auto &num : nums){
            result ^= num;
            result ^= i;
            ++i;
        }

        return result;
    }
};
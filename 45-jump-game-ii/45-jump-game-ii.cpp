class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1, count = 0, currIdx = nums[0], maxIdx = nums[0];
        
        for (int i = 1; i <= n; ++i) {
            if (currIdx < i) {
                ++count;
                currIdx = maxIdx;
            }
            if (currIdx >= n) {
                ++count;
                break;
            }
            
            int nextIdx = i + nums[i];
            if (nextIdx > maxIdx) maxIdx = nextIdx;
        }
        return count;
    }
};
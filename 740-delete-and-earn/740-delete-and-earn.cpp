class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        sort(nums.begin(), nums.end());
        int maxPoints = 0, currPoints = nums[0];
        pair<int, int> prev1 = {0, 0}, prev2 = {0, 0};
        
        for (int i = 1; i <= nums.size(); ++i) {
            int v = nums[i - 1];
            if (i < nums.size() && v == nums[i]) {
                currPoints += nums[i];
                continue;
            }
            
            int vEarned = max(currPoints + prev2.second, prev1.second);
            if (maxPoints < vEarned) maxPoints = vEarned;
            if (i < nums.size()) {
                int vNew = nums[i];
                currPoints = vNew;
                if (v == vNew - 1) prev2 = prev1;
                else prev2 = { v, vEarned };
                prev1 = { v, vEarned };
            }
        }
        return maxPoints;
    }
};
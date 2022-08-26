class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int n = nums.size() - 1;
        for (int i = n - 1; i >= 0; --i)
            if (nums[i] + i >= n) n = i;
        return n <= 0;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex)
            if (nums[fastIndex] != 0)
                nums[slowIndex++] = nums[fastIndex];
        for (int i = slowIndex; i < nums.size(); ++i) nums[i] = 0;
    }
};
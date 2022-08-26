class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        for (int& num : nums) ans ^= num;
        for (int i = 1; i <= nums.size(); ++i) ans ^= i;
        return ans;
    }
};
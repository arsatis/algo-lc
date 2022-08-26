class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> count(k, 0);
        int sum = 0;
        for (auto& x : nums) {
            sum += (x % k + k) % k;
            ++count[sum % k];
        }
        int result = count[0];
        for (auto& c : count) result += (c * (c - 1)) / 2;
        return result;
    }
};
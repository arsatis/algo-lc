class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) {
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};
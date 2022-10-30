class Solution {
    bool f(vector<int>& nums, int start, int end) {
        if (end - start <= 2) return true;
        vector<int> seq(nums.begin() + start, nums.begin() + end);
        sort(seq.begin(), seq.end());
        
        int diff = seq[1] - seq[0];
        for (int i = 2; i < seq.size(); ++i) if (seq[i] - seq[i - 1] != diff) return false;
        return true;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> output(l.size());
        for (int i = 0; i < l.size(); ++i) output[i] = f(nums, l[i], r[i] + 1);
        return move(output);
    }
};
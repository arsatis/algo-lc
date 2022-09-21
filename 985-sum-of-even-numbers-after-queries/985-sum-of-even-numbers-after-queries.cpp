class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        vector<int> output;
        output.reserve(nums.size());
        
        for (int i : nums) if (i % 2 == 0) evenSum += i;
        for (auto& v : queries) {
            if (nums[v[1]] % 2 == 0) evenSum -= nums[v[1]];
            nums[v[1]] += v[0];
            if (nums[v[1]] % 2 == 0) evenSum += nums[v[1]];
            output.emplace_back(evenSum);
        }
        return move(output);
    }
};
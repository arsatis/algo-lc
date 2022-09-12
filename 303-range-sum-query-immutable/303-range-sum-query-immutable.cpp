class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        sums.reserve(nums.size());
        for (int i : nums) sums.emplace_back(i + (sums.empty() ? 0 : sums.back()));
    }
    
    int sumRange(int left, int right) {
        return sums[right] - (left == 0 ? 0 : sums[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
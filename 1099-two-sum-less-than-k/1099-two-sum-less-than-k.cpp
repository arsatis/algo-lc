class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        // counting sort
        int m = *max_element(nums.begin(), nums.end()), mx = -1, *arr = new int[m + 1];
        for (int i = 0; i <= m; ++i) arr[i] = 0;
        for (int x : nums) ++arr[x];

        // two pointers to find max value
        for (int l = 0, r = m; l < r;) {
            while (arr[l] == 0) ++l;
            while (arr[r] == 0) --r;
            if (l == r && arr[l] < 2) break;
            int curr = l + r;
            if (curr == k - 1) return curr;
            else if (curr < k) ++l, mx = max(mx, curr);
            else --r;
        }
        return mx;
    }
};

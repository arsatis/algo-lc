class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        int n = s.size(), arr0[n + 1], arr1[n + 1];

        // find num flips needed to make s monotone 0 or 1
        arr0[0] = 0;
        arr1[n] = 0;
        for (int i = 1; i <= n; ++i) arr0[i] = arr0[i - 1] + (s[i - 1] != '0');
        for (int i = n - 1; i >= 0; --i) arr1[i] = arr1[i + 1] + (s[i] != '1');

        // find min across all indices
        int minFlips = 1e5;
        for (int i = 0; i <= n; ++i) if (minFlips > arr0[i] + arr1[i]) minFlips = arr0[i] + arr1[i];
        return minFlips;
    }
};

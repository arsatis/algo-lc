class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> vvl(n, vector<long>(5, 0));
        int mod = 1e9 + 7;
        
        for (int i = 0; i < 5; ++i) vvl[0][i] = 1;
        for (int i = 0; i < n - 1; ++i) {
            vvl[i + 1][0] = (vvl[i][1] + vvl[i][2] + vvl[i][4]) % mod;
            vvl[i + 1][1] = (vvl[i][0] + vvl[i][2]) % mod;
            vvl[i + 1][2] = (vvl[i][1] + vvl[i][3]) % mod;
            vvl[i + 1][3] = vvl[i][2] % mod;
            vvl[i + 1][4] = (vvl[i][2] + vvl[i][3]) % mod;
        }
        
        for (int i = 1; i < 5; ++i) vvl[n - 1][0] += vvl[n - 1][i];
        return vvl[n - 1][0] % mod;
    }
};
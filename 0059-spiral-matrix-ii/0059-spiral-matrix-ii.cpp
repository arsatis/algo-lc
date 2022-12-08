class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int k = 1, l = 0, r = n - 1;
        while (l <= r) {
            cout << k << ' ' << l << ' ' << r << '\n';
            int diff = r - l;
            if (diff == 0) matrix[l][r] = k;
            else for (int i = 0; i < diff; ++i) {
                matrix[l][l + i] = k + i;
                matrix[l + i][r] = k + i + diff;
                matrix[r][r - i] = k + i + (diff << 1);
                matrix[r - i][l] = k + i + diff * 3;
            }
            k += diff << 2;
            ++l, --r;
        }
        return move(matrix);
    }
};

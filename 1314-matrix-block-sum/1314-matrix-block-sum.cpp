class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n, vector<int>(m,0)), ans(n, vector<int>(m,0));
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                pref[i][j] += (j==0) ? mat[i][j] : pref[i][j-1] + mat[i][j];
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] += pref[i-1][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int minRow = max(0, i-k), maxRow = min(n-1, i+k), minCol = max(0, j-k), maxCol = min(m-1, j+k);
              
                int val1 = minCol==0 ? 0 : pref[maxRow][minCol-1];
                int val2 = minRow==0 ? 0 : pref[minRow-1][maxCol];
                int val3 = minRow==0 || minCol==0 ? 0 : pref[minRow-1][minCol-1];
                
                ans[i][j] = pref[maxRow][maxCol] - val1 - val2 + val3;
            }
        }
        return ans;
    }
};
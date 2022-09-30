class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 1; i < m; i++)
            mat[i][0] += mat[i-1][0];
        
        for (int i = 1; i < n; i++)
            mat[0][i] += mat[0][i-1];
        
        for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        
        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int left = max(i-k, 0);
            int right = min(i+k, m-1);
            int up = max(j-k, 0);
            int down = min(j+k, n-1);
            
            if (left == 0 && up == 0)
                result[i][j] = mat[right][down];
            else if (left == 0)
                result[i][j] = mat[right][down] - mat[right][up-1];
            else if(up == 0)
                result[i][j] = mat[right][down] - mat[left-1][down];
            else
                result[i][j] = mat[right][down] - mat[left-1][down] - mat[right][up-1] + mat[left-1][up-1];
        }
        
        return result; 
    }
};
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), size = m * n;
        int left = 0, up = 0, right = n - 1, down = m - 1;
        vector<int> elements;
        elements.reserve(size);
        
        while (elements.size() < size) {
            for (int i = left; i <= right; ++i)
                elements.emplace_back(matrix[up][i]);
            for (int i = up + 1; i <= down; ++i)
                elements.emplace_back(matrix[i][right]);
            if (up != down)
                for (int i = right - 1; i >= left; --i)
                    elements.emplace_back(matrix[down][i]);
            if (left != right)
                for (int i = down - 1; i > up; --i)
                    elements.emplace_back(matrix[i][left]);
            ++left, ++up, --right, --down;
        }
        return elements;
    }
};
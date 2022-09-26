class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, left = 0, down = matrix.size() - 1, right = matrix[0].size() - 1;
        while (top < down) {
            int mid = (top + down) >> 1;
            if (target >= matrix[mid][0] and target < matrix[mid + 1][0]) {
                top = mid;
                break;
            }
            else if (target < matrix[mid][0]) down = mid - 1;
            else top = mid + 1;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            if (target == matrix[top][mid]) return true;
            else if (target < matrix[top][mid]) right = mid - 1;
            else left = mid + 1;
        }
        return matrix[top][left] == target;
    }
};
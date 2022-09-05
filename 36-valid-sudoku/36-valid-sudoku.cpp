class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; ++i) {
            int arr[9] = { 0 };
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.' && arr[board[i][j] - '1']++ > 0)
                    return false;
        }
        
        // col
        for (int j = 0; j < 9; ++j) {
            int arr[9] = { 0 };
            for (int i = 0; i < 9; ++i)
                if (board[i][j] != '.' && arr[board[i][j] - '1']++ > 0)
                    return false;
        }
        
        // square
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int arr[9] = { 0 };
                for (int di = 0; di < 3; ++di)
                    for (int dj = 0; dj < 3; ++dj)
                        if (board[i + di][j + dj] != '.' &&
                            arr[board[i + di][j + dj] - '1']++ > 0)
                            return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int sub[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0' - 1; //convert int and remove off by one error
                int subBoxNum  = (i/3)*3 + j/3;
                if (row[i][num] || col[j][num] || sub[subBoxNum][num]) {
                    return false;
                } else {
                    row[i][num] = col[j][num] = sub[subBoxNum][num] = 1;
                }
            } 
        }
        return true;
    }
};
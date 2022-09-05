class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != '.'){
                    int b = i/3 * 3 +j/3;
                    int x = board[i][j]-'0'-1;
                    if(row[i][x] == 1 or col[j][x] == 1 or box[b][x] == 1){
                        return false;
                    }
                    row[i][x] = 1;
                    col[j][x] = 1;
                    box[b][x] = 1;
                }
            }
        }
        return true;
    }
};
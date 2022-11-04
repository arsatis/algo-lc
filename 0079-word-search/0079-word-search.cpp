class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx >= word.size()) return true;
        bool exist = false;
        board[i][j] = '.';
        if (i > 0 && board[i - 1][j] == word[idx]) exist |= dfs(board, word, i - 1, j, idx + 1);
        if (j > 0 && board[i][j - 1] == word[idx]) exist |= dfs(board, word, i, j - 1, idx + 1);
        if (i < board.size() - 1 && board[i + 1][j] == word[idx])
            exist |= dfs(board, word, i + 1, j, idx + 1);
        if (j < board[0].size() - 1 && board[i][j + 1] == word[idx])
            exist |= dfs(board, word, i, j + 1, idx + 1);
        board[i][j] = word[idx - 1];
        return exist;
    }
public:
    bool exist(vector<vector<char>>& board, string& word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == word[0] && dfs(board, word, i, j, 1)) return true;
        return false;
    }
};

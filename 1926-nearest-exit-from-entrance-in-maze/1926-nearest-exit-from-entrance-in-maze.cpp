class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size() - 1, n = maze[0].size() - 1, minSteps = 0;
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                
                if ((i * j == 0 || i == m || j == n) &&
                    !(i == entrance[0] && j == entrance[1])) return minSteps;
                if (i > 0 && maze[i - 1][j] == '.') {
                    maze[i - 1][j] = '+';
                    q.emplace(i - 1, j);
                }
                if (j > 0 && maze[i][j - 1] == '.') {
                    maze[i][j - 1] = '+';
                    q.emplace(i, j - 1);
                }
                if (i < m && maze[i + 1][j] == '.') {
                    maze[i + 1][j] = '+';
                    q.emplace(i + 1, j);
                }
                if (j < n && maze[i][j + 1] == '.') {
                    maze[i][j + 1] = '+';
                    q.emplace(i, j + 1);
                }
            }
            ++minSteps;
        }
        return -1;
    }
};
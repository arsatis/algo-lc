class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int lastPlayer = 0, loses[100001];
        fill(loses, loses + 100001, 100001);
        for (auto& match : matches) {
            for (int i = 0; i < 2; ++i) if (loses[match[i]] == 100001) loses[match[i]] = 0;
            ++loses[match[1]];
            lastPlayer = max(lastPlayer, max(match[0], match[1]));
        }

        vector<vector<int>> winners(2);
        for (int i = 1; i <= lastPlayer; ++i)
            if (loses[i] <= 1) winners[loses[i]].emplace_back(i);
        return move(winners);
    }
};

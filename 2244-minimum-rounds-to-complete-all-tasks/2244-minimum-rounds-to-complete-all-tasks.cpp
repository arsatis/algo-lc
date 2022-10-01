class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskCount;
        for (int i : tasks) ++taskCount[i];
        
        int rounds = 0;
        for (auto& p : taskCount) {
            if (p.second == 1) return -1;
            rounds += ceil(p.second / 3.);
        }
        return rounds;
    }
};
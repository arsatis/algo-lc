class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        map<int, int> counts;
        int i = 0, j = 0, prev = 10002;
        
        for (int x : nums) counts[x] += x;
        for (auto it = counts.rbegin(); it != counts.rend(); ++it) {
            int tmp = j;
            if (prev - it->first > 1) {
                j = max(i, j) + it->second;
                prev = it->first;
            } else if (i + it->second > j) {
                j = i + it->second;
                prev = it->first;
            }
            i = tmp;
        }
        return j;
    }
};
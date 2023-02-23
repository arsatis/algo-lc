class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        pair<int, int> summary[n];
        for (int i = 0; i < n; ++i) summary[i] = {profits[i], capital[i]};
        sort(summary, summary + n, [](auto& p1, auto& p2) {
            return p1.second < p2.second;
        });

        int i = 0;
        priority_queue<int> pq;
        for (int j = 0; j < k; ++j) {
            while (i < n && summary[i].second <= w) pq.emplace(summary[i++].first);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

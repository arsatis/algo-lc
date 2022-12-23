class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : sticks) pq.emplace(x);
        while (pq.size() > 1) {
            int tmp = pq.top(); pq.pop();
            tmp += pq.top(); pq.pop();
            total += tmp;
            pq.emplace(tmp);
        }
        return total;
    }
};

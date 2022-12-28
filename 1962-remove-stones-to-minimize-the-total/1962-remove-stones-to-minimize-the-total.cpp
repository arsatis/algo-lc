class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int rem = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq;
        for (int x : piles) pq.emplace(x);
        for (int i = 0; i < k; ++i) {
            int d = pq.top() >> 1;
            rem -= d;
            pq.emplace(pq.top() - d);
            pq.pop();
        }
        return rem;
    }
};

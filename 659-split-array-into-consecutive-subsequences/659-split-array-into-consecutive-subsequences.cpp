class Solution {
public:
    bool isPossible(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({nums[0], 1});
        
        for (int i = 1; i < nums.size(); ++i) {
            while (!pq.empty() && pq.top().first + 1 < nums[i]) {
                if (pq.top().second < 3) return false;
                pq.pop();
            }
            
            if (pq.top().first + 1 != nums[i]) pq.push({nums[i], 1});
            else {
                int count = pq.top().second + 1;
                pq.pop();
                pq.push({nums[i], count});
            }
        }
        
        while (!pq.empty()) {
            if (pq.top().second < 3) return false;
            pq.pop();
        }
        return true;
    }
};
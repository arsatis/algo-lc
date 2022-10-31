class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size());
        stack<int> st;
        
        for (int rounds = 0; rounds < 2; ++rounds) {
            for (int i = nums.size() - 1; i >= 0; --i) {
                while (!st.empty() && st.top() <= nums[i]) st.pop();
                if (st.empty()) nge[i] = -1;
                else nge[i] = st.top();
                st.emplace(nums[i]);
            }
        }
        return move(nge);
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i)
            ans[i] = m.count(nums1[i]) ? m[nums1[i]] : -1;
        return ans;
    }
};
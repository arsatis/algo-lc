class Solution {
public:
    void rotate(vector<int>& v, int k) {
        ios_base::sync_with_stdio(0);
        std::rotate(v.rbegin(), v.rbegin() + k % v.size(), v.rend());
    }
};
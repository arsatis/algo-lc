class Solution {
    vector<int> vi;
    
    void f(int i, int n, int k) {
        if (n == 1) vi.push_back(i);
        else {
            int rem = i % 10;
            if (rem - k >= 0) f(i * 10 + rem - k, n - 1, k);
            if (k && rem + k < 10) f(i * 10 + rem + k, n - 1, k);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        ios_base::sync_with_stdio(0);
        
        for (int i = 1; i < 10; ++i) f(i, n, k);
        return vi;
    }
};
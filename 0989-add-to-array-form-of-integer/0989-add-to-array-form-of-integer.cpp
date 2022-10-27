class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int i = 0;
        while (k > 0) {
            int rem = k % 10;
            k /= 10;
            if (i == num.size()) num.emplace_back(rem);
            else {
                num[i] += rem;
                if (num[i] > 9) ++k, num[i] -= 10;
            }
            ++i;
        }
        reverse(num.begin(), num.end());
        return move(num);
    }
};
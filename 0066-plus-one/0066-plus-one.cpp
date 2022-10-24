class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                ++digits[i];
                return move(digits);
            }
        }
        digits.insert(digits.begin(), 1);
        return move(digits);
    }
};
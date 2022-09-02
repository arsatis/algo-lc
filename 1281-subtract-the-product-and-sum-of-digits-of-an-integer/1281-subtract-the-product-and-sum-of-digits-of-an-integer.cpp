class Solution {
public:
    int subtractProductAndSum(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int sum = 0, product = 1;
        for (char c : to_string(n)) {
            int i = c - '0';
            sum += i, product *= i;
        }
        return product - sum;
    }
};
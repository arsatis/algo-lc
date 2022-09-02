class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        for (char c : to_string(n)) {
            int i = c - '0';
            sum += i, product *= i;
        }
        return product - sum;
    }
};
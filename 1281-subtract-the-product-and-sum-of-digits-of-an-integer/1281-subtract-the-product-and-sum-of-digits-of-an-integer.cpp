class Solution {
public:
    int subtractProductAndSum(int n) {
        ios_base::sync_with_stdio(0);
        
        int sum = 0, product = 1;
        while (n > 0) {
            sum += n % 10, product *= n % 10;
            n /= 10;
        }
        
        return product - sum;
    }
};
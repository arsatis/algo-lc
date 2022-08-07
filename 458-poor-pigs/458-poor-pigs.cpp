class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int days = minutesToTest / minutesToDie, x = days + 1;
        double a = log10(buckets), b = log10(x);
        return ceil(a / b);
    }
};
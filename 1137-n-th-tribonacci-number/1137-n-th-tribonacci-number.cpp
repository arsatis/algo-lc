class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int i = 0, j = 1, k = 1;
        while (n-- > 2) {
            swap(i += (j + k), k);
            swap(i, j);
        }
        return k;
    }
};
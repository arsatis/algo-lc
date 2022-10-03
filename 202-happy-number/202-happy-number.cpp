class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (seen.find(n) == seen.end()) {
            if (n == 1) return true;
            seen.insert(n);
            
            int temp = 0;
            while (n > 0) {
                int rem = n % 10;
                temp += (rem * rem);
                n /= 10;
            }
            n = temp;
        }
        return false;
    }
};
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nStr = to_string(n);
        int powerOfTwo = 1;
        
        // find smallest power of 2 with same num of digits as n
        while (to_string(powerOfTwo).size() < nStr.size()) powerOfTwo <<= 1;
        
        // for each val, check if { num : count } pairs are same as n
        while (to_string(powerOfTwo).size() == nStr.size()) {
            int digits[10] = { 0 };
            for (char& c : to_string(powerOfTwo)) ++digits[c - '0'];
            for (char& c : nStr) {
                if (digits[c - '0'] == 0) break;
                --digits[c - '0'];
            }
            if (accumulate(digits, digits + 10, 0) == 0) return true;
            powerOfTwo <<= 1;
        }
        return false;
    }
};
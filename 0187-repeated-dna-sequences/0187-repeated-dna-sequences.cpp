class Solution {
    int toInt(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return 4;
        }
    }
public:
    vector<string> findRepeatedDnaSequences(string& s) {
        if (s.size() < 10) return {};
        unordered_map<int, int> seen;
        vector<string> output;
        int shift = 2;      // shift factor
        int mod = 5e7 + 21; // prime to take mod against
        int multiplier = 1; // multiplier to help remove the leftmost element from the hash
        int sHash = 0;      // current hash
        int k = 10;         // number of letters per subsequence
        
        // compute the value of the multiplier
        for (int i = 1; i < k; ++i) multiplier = (multiplier << shift) % mod;

        // hash the first k elements
        for (int i = 0; i < k; ++i) sHash = ((sHash << shift) + toInt(s[i])) % mod;
        ++seen[sHash];
        
        // hash the remaining elements
        for (int i = k; i < s.size(); ++i) {
            sHash = (sHash + mod - (multiplier * (toInt(s[i - k])) % mod)) % mod; // remove leftmost element
            sHash = ((sHash << shift) + toInt(s[i])) % mod;                       // add rightmost element
            if (++seen[sHash] == 2) output.emplace_back(s.substr(i - k + 1, k));
        }
        return move(output);
    }
};

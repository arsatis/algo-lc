class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters.front() : *it;
    }
};
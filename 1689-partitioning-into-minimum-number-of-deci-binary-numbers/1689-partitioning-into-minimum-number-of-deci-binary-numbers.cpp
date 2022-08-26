class Solution {
public:
    int minPartitions(string n) {
        ios_base::sync_with_stdio(0);
        return *max_element(begin(n), end(n)) - '0';
    }
};
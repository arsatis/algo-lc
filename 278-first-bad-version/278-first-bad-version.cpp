// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        ios_base::sync_with_stdio(0);
        
        long start = 1, end = n;
        while (start < end) {
            int mid = (start + end) >> 1;
            if (isBadVersion(mid)) end = mid;
            else start = mid + 1;
        }
        return start;
    }
};
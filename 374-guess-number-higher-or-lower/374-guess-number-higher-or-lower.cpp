/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int guessNumber(int n) {
        for (long l = 0, r = n; l <= r;) {
            int mid = (l + r) >> 1;
            if (guess(mid) == 0) return mid;
            else if (guess(mid) < 0) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        short num5 = 0, num10 = 0;
        for (int x : bills) {
            if (x == 5) ++num5;
            else if (x == 10) --num5, ++num10;
            else --num10, --num5;

            if (num10 < 0) ++num10, num5 -= 2;
            if (num5 < 0) return false;
        }
        return true;
    }
};

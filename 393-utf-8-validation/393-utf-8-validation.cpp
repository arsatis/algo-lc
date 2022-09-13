class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rb = 0;
        for (int val : data) {
            if (!rb) {
                if ((val >> 7) == 0b0) rb = 0;
                else if ((val >> 5) == 0b110) rb = 1;
                else if ((val >> 4) == 0b1110) rb = 2;
                else if ((val >> 3) == 0b11110) rb = 3;
                else return false;
            } else {
                if ((val >> 6) == 0b10) --rb;
                else return false;
            }
        }
        return rb == 0;
    }
};
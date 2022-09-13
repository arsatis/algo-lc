class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // Number of bytes in the current UTF-8 character
        int numberOfBytesToProcess = 0;

        // Masks to check two most significant bits in a byte.
        int mask1 = 1 << 7, mask2 = 1 << 6;

        for (int i = 0; i < data.size(); ++i) {
            // If this is the case then we are to start processing a new UTF-8 character.
            if (numberOfBytesToProcess == 0) {
                int mask = 1 << 7;
                 while (mask & data[i]) {
                    ++numberOfBytesToProcess;
                    mask >>= 1;
                 }
                if (numberOfBytesToProcess == 0) continue;
                if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) return false;
            } else {
                // data[i] should have most significant bit set and
                // second most significant bit unset. So, we use the two masks
                // to make sure this is the case.
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }
            --numberOfBytesToProcess;
        }
        return numberOfBytesToProcess == 0;
    }
};
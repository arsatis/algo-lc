/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int col = dim[1];
        for (int i = 0; i < dim[0]; ++i)
            while (col > 0 && binaryMatrix.get(i, col - 1) == 1) --col;
        return col == dim[1] ? -1 : col;
    }
};

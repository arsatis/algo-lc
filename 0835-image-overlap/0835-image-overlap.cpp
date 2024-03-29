class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int largestOverlap(vector<vector<int>>& _img1, vector<vector<int>>& _img2) {
        int rows = _img1.size(), cols = _img1.front().size();
        
        //store image rows into bitsets
        vector<bitset<32>> img1(rows), img2(rows);
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                img1[r][c] = _img1[r][c];
                img2[r][c] = _img2[r][c];
            }
        }
        
        int overlap = 0;
        
        for(int dr = -(rows-1); dr < rows; ++dr) {
            for(int dc = -(cols-1); dc < cols; ++dc) {
                int curoverlap = 0;
                for(int r1 = 0; r1 < rows; ++r1) {
                    int r2 = r1 + dr;
                    if(r2 < 0) continue;
                    if(r2 >= rows) break;
                    auto r1r2 = img1[r1] & (dc < 0 ? img2[r2] << -dc : img2[r2] >> dc);
                    curoverlap += r1r2.count();
                }
                if(curoverlap > overlap)
                    overlap = curoverlap;
            }
        }
        
        return overlap;
    }
};
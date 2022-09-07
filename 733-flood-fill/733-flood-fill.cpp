class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (image[sr][sc] == color) return image;
        int origColor = image[sr][sc];
        image[sr][sc] = color;
        if (sr > 0 && origColor == image[sr - 1][sc])
            floodFill(image, sr - 1, sc, color);
        if (sc > 0 && origColor == image[sr][sc - 1])
            floodFill(image, sr, sc - 1, color);
        if (sr < image.size() - 1 && origColor == image[sr + 1][sc])
            floodFill(image, sr + 1, sc, color);
        if (sc < image[0].size() - 1 && origColor == image[sr][sc + 1])
            floodFill(image, sr, sc + 1, color);
        return image;
    }
};
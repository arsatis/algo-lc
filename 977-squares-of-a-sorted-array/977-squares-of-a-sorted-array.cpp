class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        vector<int> output(nums.size());
        auto posIt = lower_bound(nums.begin(), nums.end(), 0),
             negIt = posIt - 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (posIt == nums.end()) output[i] = *negIt * *(negIt--);
            else if (negIt < nums.begin() || *posIt < abs(*negIt)) output[i] = *posIt * *(posIt++);
            else output[i] = *negIt * *(negIt--);
        }
        return output;
    }
};
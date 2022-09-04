class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        
        sort(arr.begin(), arr.end());
        
        for (int i = 2; i < arr.size(); ++i)
            if (arr[i] + arr[i - 2] != arr[i - 1] * 2)
                return false;
        return true;
    }
};
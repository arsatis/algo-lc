class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i)
            if (arr[i] - arr[i - 1] != diff)
                return false;
        return true;
    }
};
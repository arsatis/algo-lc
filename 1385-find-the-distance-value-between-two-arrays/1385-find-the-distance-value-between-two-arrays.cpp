class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        int dist = 0;
        for (int i = 0, j = 0; i < arr1.size(); ++i) {
            if (j == arr2.size()) ++dist;
            else {
                bool hasElement = false;
                while (j < arr2.size() && arr2[j] - d <= arr1[i]) {
                    if (abs(arr1[i] - arr2[j]) > d) ++j;
                    else {
                        hasElement = true;
                        break;
                    }
                }
                if (!hasElement) ++dist;
            }
        }
        return dist;
    }
};
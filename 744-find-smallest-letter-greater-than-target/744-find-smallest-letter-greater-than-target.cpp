class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        char ans = letters[0];
        while (l <= r) {
            int i = (l + r) >> 1;
            if (letters[i] > target){
                r = i - 1;
                ans = letters[i];
            }
            else l = i+1;
        }
        return ans;
    }
};
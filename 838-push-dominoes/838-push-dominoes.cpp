class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string pushDominoes(string dominoes) {
        bool hasRight = false;
        int left, right;
        
        for (left = 0, right = 0; right < dominoes.size(); ++right) {
            if (dominoes[right] == 'R') {
                if (hasRight) while (left < right) dominoes[left++] = 'R';
                else hasRight = true;
                left = right;
            } else if (dominoes[right] == 'L') {
                if (!hasRight) for (int i = left; i < right; ++i) dominoes[i] = 'L';
                else {
                    for (int i = left, j = right; i < j; ++i, --j) dominoes[i] = 'R', dominoes[j] = 'L';
                    hasRight = false;
                    left = right;
                }
            }
        }
        if (hasRight) while (left < right) dominoes[left++] = 'R';
        return move(dominoes);
    }
};
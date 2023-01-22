class Solution {
public:
    int minimumBuckets(string& hamsters) {
        int buckets = 0;
        for (int i = 0; i < hamsters.size(); ++i) {
            if (hamsters[i] == 'H') {
                if (i < hamsters.size() - 1 && hamsters[i + 1] == '.')
                    hamsters[i + 1] = 'd';
                else if (i > 0 && hamsters[i - 1] == '.')
                    hamsters[i - 1] = 'd';
                else return -1;
                ++buckets;
            } else if (hamsters[i] == 'd') {
                if (i < hamsters.size() - 1 && hamsters[i + 1] == 'H')
                    hamsters[i + 1] = 'h';
            }
        }
        return buckets;
    }
};

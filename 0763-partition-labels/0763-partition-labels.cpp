class Solution {
public:
    vector<int> partitionLabels(string& s) {
        int firstpos[26], lastpos[26];
        memset(firstpos, -1, sizeof(firstpos));
        memset(lastpos, -1, sizeof(lastpos));
        for (int i = 0; i < s.size(); ++i) {
            if (firstpos[s[i] - 'a'] == -1) firstpos[s[i] - 'a'] = i;
            lastpos[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> partitions;
        for (int i = 0; i < 26; ++i)
            if (firstpos[i] != -1) partitions.emplace_back(firstpos[i], lastpos[i]);
        sort(partitions.begin(), partitions.end());

        vector<int> sizes;
        if (partitions.empty()) sizes.resize(s.size()), fill(sizes.begin(), sizes.end(), 1);
        else {
            int l = partitions[0].first, r = partitions[0].second;
            for (int i = 1; i < partitions.size(); ++i) {
                if (r < partitions[i].first) {
                    sizes.emplace_back(r - l + 1);
                    l = partitions[i].first;
                }
                r = max(r, partitions[i].second);
            }
            sizes.emplace_back(r - l + 1);
        }
        return sizes;
    }
};

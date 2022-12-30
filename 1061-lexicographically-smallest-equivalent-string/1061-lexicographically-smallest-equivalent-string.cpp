class Solution {
    int rep[26] = {};

    int find(int n) {
        if (rep[n] == n) return n;
        return rep[n] = find(rep[n]);
    }
public:
    string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
        iota(rep, rep + 26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            int set1 = find(s1[i] - 'a'), set2 = find(s2[i] - 'a');
            if (set1 < set2) rep[set2] = rep[set1];
            else rep[set1] = rep[set2];
        }

        string output = "";
        for (char c : baseStr) output += string(1, find(c - 'a') + 'a');
        return output;
    }
};

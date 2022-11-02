class Solution {
public:
    int minMutation(string& start, string& end, vector<string>& bank) {
        int num = 0;
        unordered_set<string> seen, bankset;
        seen.emplace(start);
        for (string& s : bank) bankset.insert(s);
        queue<string> q;
        q.emplace(start);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string gene = q.front();
                q.pop();
                if (gene == end) return num;
                for (char& c : gene) {
                    char tmp = c;
                    for (char c2 : "ACGT") {
                        c = c2;
                        if (!seen.count(gene) && bankset.count(gene)) {
                            q.emplace(gene);
                            seen.insert(gene);
                        }
                    }
                    c = tmp;
                }
            }
            ++num;
        }
        return -1;
    }
};
class Solution {
public:
    int minMutation(string& start, string& end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.emplace(start);
        seen.insert(start);
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string& node = q.front();
                q.pop();

                if (node == end) return steps;
                for (char c : "ACGT") {
                    for (int i = 0; i < node.size(); ++i) {
                        string neighbor = node;
                        neighbor[i] = c;
                        if (!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            q.emplace(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
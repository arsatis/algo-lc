class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) return node1;
        bool v1[edges.size()], v2[edges.size()];
        memset(v1, false, sizeof(v1));
        memset(v2, false, sizeof(v2));
        v1[node1] = true, v2[node2] = true;

        vector<int> ans;
        ans.reserve(2);
        while (node1 != -1 || node2 != -1) {
            if (node1 != -1 && (node1 = edges[node1]) != -1) {
                if (v2[node1]) ans.emplace_back(node1);
                else if (v1[node1]) node1 = -1; // node has been visited, we are in a loop
                else v1[node1] = true;
            }
            if (node2 != -1 && (node2 = edges[node2]) != -1) {
                if (v1[node2]) ans.emplace_back(node2);
                else if (v2[node2]) node2 = -1;
                else v2[node2] = true;
            }
            if (!ans.empty()) return *min_element(ans.begin(), ans.end());
        }
        return -1;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (!visited[curr])
                visited[curr] = new Node(curr->val, vector<Node*>(curr->neighbors.size()));
            for (int i = 0; i < curr->neighbors.size(); ++i) {
                Node* n = curr->neighbors[i];
                if (!visited[n]) {
                    visited[n] = new Node(n->val, vector<Node*>(n->neighbors.size()));
                    q.push(n);
                }
                visited[curr]->neighbors[i] = visited[n];
            }
        }
        
        return visited[node];
    }
};
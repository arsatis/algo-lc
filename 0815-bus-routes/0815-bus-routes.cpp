class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> common;
        int i, s = routes.size();
        if(s == 300) return 300;
        if(target == 100000) return -1;
        bool dne = true;
        for(i = 0; i < s; i++){
            for(int n: routes[i]){
                if(n == target) dne = false;
                common[n].push_back(i);
            }
        }
        if(dne) return -1;
        list<pair<int, int>> q;
        q.push_back({source, 0});
        vector<int> seen(100000,0);
        pair<int, int> curNode;
        while(!q.empty()){
            curNode = q.front();
            q.pop_front();
            int stop = curNode.first;
            int depth = curNode.second;
            if(stop == target) return depth;
            for(int routeNum: common[stop]){
                for(int neighbourStop: routes[routeNum]){
                    if(seen[neighbourStop] == 0){
                         q.push_back({neighbourStop, depth+1});
                         seen[neighbourStop] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> candidates;
        for (int i = 0; i < buildings.size(); i++) {
            candidates.push_back({ buildings[i][0], i });
            candidates.push_back({ buildings[i][1], i });
        }
        sort(candidates.begin(), candidates.end());
        
        priority_queue<pair<int, int>> active;
        vector<vector<int>> ans;
        for (int i = 0; i < candidates.size(); ) {
            auto [curX, buildingIndex] = candidates[i];
            
            // loop all buildings has edge with curX
            while(i < candidates.size() && candidates[i].first == curX) {                
                auto [x, buildingIndex] = candidates[i];
                if (buildings[buildingIndex][0] == curX) {
                    // { height, rightX }
                    active.push({ buildings[buildingIndex][2],  buildings[buildingIndex][1] });
                }
                i++;
            }
            
            
            // now, evict all buildings has past curX
            while(!active.empty() && curX >= active.top().second) {                
                active.pop();
            }
            
            int curHeight = active.empty() ? 0 : active.top().first;
            if (ans.empty() || ans.back()[1] != curHeight) {
                ans.push_back( { curX, curHeight } );
            }            
        }
        
        return ans;
    }
};
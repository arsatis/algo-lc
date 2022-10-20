class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        res.reserve(intervals.size() + 1);
        for(int i=0;i<intervals.size();i++){
            if(newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                newInterval=intervals[i];
            }else if(newInterval[0] > intervals[i][1]){
                res.push_back(intervals[i]);
            }else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
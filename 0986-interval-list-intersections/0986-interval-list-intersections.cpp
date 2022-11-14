class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> output;
        for (int ptr1 = 0, ptr2 = 0; ptr1 < firstList.size() && ptr2 < secondList.size();) {
            if (firstList[ptr1][1] >= secondList[ptr2][0] && secondList[ptr2][1] >= firstList[ptr1][0]) {
                output.push_back({max(firstList[ptr1][0], secondList[ptr2][0]),
                                    min(firstList[ptr1][1], secondList[ptr2][1])});
            }
            if (firstList[ptr1][1] > secondList[ptr2][1]) ++ptr2;
            else ++ptr1;
        }
        return move(output);
    }
};

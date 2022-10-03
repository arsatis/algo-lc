class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int minCost(string& colors, vector<int>& neededTime) {
        int totalTime = 0;
        for (int left = 0, right = 0; right < colors.size();) {
            int currTime = 0, currMax = 0;
            while (right < colors.size() && colors[left] == colors[right]) {
                currMax = max(currMax, neededTime[right]);
                currTime += neededTime[right++];
            }
            totalTime += currTime - currMax;
            left = right;
        }
        return totalTime;
    }
};

// Solution 1: Two pointers
// int minCost(string& colors, vector<int>& neededTime) {
//     int totalTime = 0;
//     for (int left = 0, right = 0; right < colors.size();) {
//         int currTime = 0, currMax = 0;
//         while (right < colors.size() && colors[left] == colors[right]) {
//             currMax = max(currMax, neededTime[right]);
//             currTime += neededTime[right++];
//         }
//         totalTime += currTime - currMax;
//         left = right;
//     }
//     return totalTime;
// }

// Solution 2: Single-pass greedy
// int minCost(string& colors, vector<int>& neededTime) {
//     int totalTime = 0, currMax = 0;
//     for (int i = 0; i < colors.size(); ++i) {
//         if (i > 0 && colors[i] != colors[i - 1]) currMax = 0;
//         totalTime += min(currMax, neededTime[i]);
//         currMax = max(currMax, neededTime[i]);
//     }
//     return totalTime;
// }
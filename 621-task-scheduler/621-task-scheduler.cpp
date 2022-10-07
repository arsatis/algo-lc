class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        
        // find count for each task
        int taskCounts[26] = {};
        for (char c : tasks) ++taskCounts[c - 'A'];
        
        // find num tasks with max count
        int maxCount = 0, otherCount = 0, numMaxCountTasks = 0;
        for (int i : taskCounts) {
            if (maxCount > i) otherCount += i;
            else if (maxCount == i) ++numMaxCountTasks;
            else {
                otherCount += maxCount * numMaxCountTasks;
                maxCount = i;
                numMaxCountTasks = 1;
            }
        }
        
        // find num idles needed
        if (numMaxCountTasks > n) return tasks.size();
        else {
            int numIdles = (maxCount - 1) * (n - numMaxCountTasks + 1) - otherCount;
            return tasks.size() + (numIdles < 0 ? 0 : numIdles);
        }
    }
};

// Case 1: numMaxCountTasks == 1
// let x = (maxCount - 1) * n (i.e., number of other tasks required)
// - Case 1a: otherCount - x >= 0: return tasks.size()
// - Case 1b: otherCount - x < 0: return tasks.size() + (x - otherCount)
// Case 2: numMaxCountTasks > 1, <= n
// let x = (maxCount - 1) * n - (maxCount - 1) * (numMaxCountTasks - 1) (i.e., number of other tasks required)
// - Case 2a: otherCount - x >= 0: return tasks.size()
// - Case 2b: otherCount - x < 0: return tasks.size() + (x - otherCount)
// Case 3: numMaxCountTasks > n: return tasks.size()
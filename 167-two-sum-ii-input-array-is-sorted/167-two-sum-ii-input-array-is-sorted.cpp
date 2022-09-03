class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(0);
        
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) return { left + 1, right + 1 };
            else if (numbers[left] + numbers[right] < target) ++left;
            else --right;
        }
        return {};
    }
};